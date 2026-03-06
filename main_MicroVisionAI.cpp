/*
 * @file main.cpp (MicroVision AI Project)
 * @brief GPT-4o Image Question-Answering on ESP32
 * 
 * Integrates ESP32 with OpenAI's GPT-4o Vision API for real-time
 * image question-answering via serial communication
 * 
 * @author Pavan Kumar Ginkala
 * @version 1.0.0
 * @date 2025-01-15
 * 
 * Hardware: ESP32 DevKit V1, WiFi enabled
 * Dependencies: ArduinoJson, WiFiClientSecure, HTTPClient
 * 
 * SECURITY WARNING: Use secrets.h for API keys, NOT hardcoded values!
 */

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Use secrets.h for production (create this file locally, not in GitHub!)
// #include "secrets.h"

// For testing ONLY - REPLACE WITH YOUR ACTUAL CREDENTIALS
// NEVER commit these to GitHub!
const char* WIFI_SSID = "your_wifi_ssid_here";
const char* WIFI_PASSWORD = "your_wifi_password_here";
const char* API_KEY = "sk-proj-your_api_key_here";

// API endpoint
const char* ENDPOINT = "https://api.openai.com/v1/chat/completions";

/**
 * @brief Setup function - Initialize WiFi and serial
 */
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n🔌 Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi Connected!");
    Serial.print("📡 IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ WiFi Connection Failed!");
    Serial.println("Check your WiFi credentials in the code");
  }
  
  Serial.println("\n🎯 MicroVision AI - GPT-4o Vision Integration");
  Serial.println("=========================================");
  Serial.println("Enter an image URL for analysis:");
}

/**
 * @brief Send image URL and question to OpenAI GPT-4o
 * @param imageUrl URL of the image to analyze
 * @param question Natural language question about the image
 * @return Response from OpenAI API
 */
String sendToOpenAI(String imageUrl, String question) {
  // Validate inputs
  if (imageUrl.length() == 0 || question.length() == 0) {
    return "❌ Error: Empty image URL or question";
  }

  WiFiClientSecure client;
  client.setInsecure(); // ⚠️ For testing only - use CA cert in production!
  HTTPClient http;

  if (!http.begin(client, ENDPOINT)) {
    return "❌ Failed to connect to OpenAI endpoint";
  }

  // Set headers
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", String("Bearer ") + API_KEY);

  // Build JSON request for GPT-4o Vision
  String postBody = "{";
  postBody += "\"model\": \"gpt-4o-mini-2024-07-18\",";
  postBody += "\"messages\": [{";
  postBody += "\"role\": \"user\",";
  postBody += "\"content\": [";
  postBody += "{\"type\": \"text\", \"text\": \"" + question + "\"},";
  postBody += "{\"type\": \"image_url\", \"image_url\": {\"url\": \"" + imageUrl + "\"}}";
  postBody += "]";
  postBody += "}],";
  postBody += "\"max_tokens\": 1024";
  postBody += "}";

  Serial.println("\n📤 Sending request to OpenAI...");

  int httpResponseCode = http.POST(postBody);
  String payload = "";

  if (httpResponseCode > 0) {
    Serial.printf("🌐 HTTP Response Code: %d\n", httpResponseCode);
    payload = http.getString();

    if (httpResponseCode == 200) {
      // Parse JSON response
      DynamicJsonDocument doc(8192);
      DeserializationError error = deserializeJson(doc, payload);
      
      if (!error) {
        if (doc["choices"][0]["message"]["content"].is<String>()) {
          String response = doc["choices"][0]["message"]["content"].as<String>();
          http.end();
          return response;
        } else {
          http.end();
          return "⚠️ No text content found in response.";
        }
      } else {
        http.end();
        return "⚠️ JSON parse error: " + String(error.c_str());
      }
    } else {
      http.end();
      return "⚠️ HTTP error " + String(httpResponseCode);
    }
  } else {
    http.end();
    return "❌ Connection failed, Error: " + String(httpResponseCode);
  }
}

/**
 * @brief Main loop - Handle serial input and API calls
 */
void loop() {
  static String imageUrl = "";
  static bool waitingForQuestion = false;

  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() == 0) {
      return; // Ignore empty input
    }

    if (!waitingForQuestion) {
      // First input: image URL
      imageUrl = input;
      Serial.println("✅ Image URL received. Now enter your question:");
      waitingForQuestion = true;
    } else {
      // Second input: question about image
      String question = input;
      waitingForQuestion = false;
      Serial.println("\n[ChatGPT] - Analyzing the provided image URL and question...");
      Serial.println("Please wait...\n");

      // Check WiFi connection
      if (WiFi.status() != WL_CONNECTED) {
        Serial.println("❌ WiFi disconnected! Reconnecting...");
        WiFi.reconnect();
        delay(2000);
      }

      // Send request to OpenAI
      String result = sendToOpenAI(imageUrl, question);
      
      Serial.println("\n🧠 Description / Response:");
      Serial.println(result);
      Serial.println("\n=========================================");
      Serial.println("Enter another image URL for analysis:");
      
      imageUrl = "";
    }
  }
}
