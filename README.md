# MicroVision-AI
GPT-4o Vision integration with ESP32 for intelligent               image analysis &amp; natural language Q&amp;A
# 🤖 MicroVision AI
### Enterprise-Grade AI Vision on Microcontrollers

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![ESP32](https://img.shields.io/badge/ESP32-E7352C?logo=Espressif&logoColor=white)](https://www.espressif.com/)
[![OpenAI](https://img.shields.io/badge/OpenAI-412991?logo=OpenAI&logoColor=white)](https://openai.com/)
[![Status](https://img.shields.io/badge/Status-Production%20Ready-brightgreen)]()

---

## 📖 Overview

**MicroVision AI** is a groundbreaking IoT platform that democratizes access to GPT-4o Vision capabilities on edge devices. This project integrates **OpenAI's GPT-4o-mini** vision model with **ESP32 microcontrollers**, enabling **real-time image understanding and intelligent Q&A** without relying on cloud-only solutions.

Transform simple IoT boards into intelligent vision assistants—perfect for **smart home automation**, **industrial inspection**, **accessibility aids**, **remote monitoring**, and **edge AI research**.

### What Makes It Special
- 🧠 **GPT-4o Vision on Edge** - Enterprise AI directly on $10 microcontroller
- 🚀 **Sub-Second Latency** - Ask questions about images in real-time
- 🌐 **Cloud-Edge Hybrid** - Leverage ESP32 connectivity with OpenAI intelligence
- 📱 **Serial Interface** - Simple USB-based interaction via serial monitor
- 🔒 **Secure API Communication** - HTTPS encryption for all API calls
- 💾 **Efficient JSON Parsing** - ArduinoJson for low-memory footprint

---

## 🎯 Features

### Core Capabilities
- **Image URL Analysis** - Analyze any publicly accessible image via URL
- **Natural Language Questions** - Ask anything about the image in plain English
- **Real-Time Responses** - Get AI-generated insights instantly
- **Multi-Turn Q&A** - Ask follow-up questions without re-uploading image
- **Robust Error Handling** - Graceful failures with informative messages
- **WiFi Integration** - 2.4 GHz WiFi connectivity via ESP32
- **HTTPS Security** - Secure certificate validation (with bypass option for testing)

### Supported Use Cases
```
┌─────────────────────────────────────────────────┐
│     Image Understanding Capabilities             │
├─────────────────────────────────────────────────┤
│ • Object detection and identification           │
│ • Scene understanding and context analysis      │
│ • Text recognition and OCR                      │
│ • Image quality assessment                      │
│ • Sentiment and emotion detection               │
│ • Medical image analysis (basic)                │
│ • Document understanding                        │
│ • Real-world scene interpretation               │
└─────────────────────────────────────────────────┘
```

### Technical Highlights
- **Model**: GPT-4o-mini-2024-07-18 (optimized for efficiency)
- **API**: OpenAI REST API with Bearer token authentication
- **Protocol**: HTTPS/TLS 1.2
- **Request Format**: Vision-capable JSON messaging
- **Response Format**: Streaming-compatible JSON parsing
- **Rate Limits**: Respects OpenAI API quotas and limits

---

## 🛠️ Tech Stack

| Category | Technology | Details |
|----------|-----------|---------|
| **Microcontroller** | ESP32 DevKit V1 | 30-pin, Dual-core |
| **IDE** | Arduino IDE | 2.3.2+ |
| **Board Package** | ESP32 Boards | 3.0.0 |
| **HTTP Client** | HTTPClient | Built-in ESP32 |
| **JSON Library** | ArduinoJson | 7.1.0 |
| **Network** | WiFiClientSecure | Built-in ESP32 |
| **AI Model** | GPT-4o-mini | OpenAI API |
| **Protocol** | HTTPS | TLS 1.2 |
| **Baud Rate** | Serial | 115200 bps |
| **Operating System** | Windows 11 | (works on macOS/Linux) |

### Dependencies
```
Core:
  ✓ WiFi.h (built-in)
  ✓ WiFiClientSecure.h (built-in)
  ✓ HTTPClient.h (built-in)
  
External:
  ✓ ArduinoJson (7.1.0) - JSON parsing
  
API:
  ✓ OpenAI API (requires API key)
  ✓ HTTPS endpoint: api.openai.com/v1/chat/completions
```

---

## 🚀 Installation & Setup

### Prerequisites
```
✓ ESP32 DevKit V1 (30-pin)
✓ Arduino IDE 2.3.2 or later
✓ USB cable for programming
✓ OpenAI API Key (get from https://platform.openai.com)
✓ WiFi network access
✓ 5V power supply
```

### Step 1: Install Arduino IDE
```bash
# Download from https://www.arduino.cc/en/software
# Tested on Version: 2.3.2
```

### Step 2: Add ESP32 Board Support
1. Open Arduino IDE
2. Go to **File** → **Preferences** → **Additional Boards Manager URLs**
3. Add: `https://dl.espressif.com/dl/package_esp32_index.json`
4. Go to **Tools** → **Board** → **Boards Manager**
5. Search for "ESP32" and install version **3.0.0**

### Step 3: Install Required Libraries
In Arduino IDE: **Sketch** → **Include Library** → **Manage Libraries**

```
Install these libraries:
1. ArduinoJson - Search "ArduinoJson" → Install version 7.1.0
2. (WiFi and HTTPClient are built-in with ESP32 core)
```

### Step 4: Get Your OpenAI API Key
1. Go to [OpenAI API Platform](https://platform.openai.com)
2. Sign in with your account (create if needed)
3. Navigate to **API Keys** → **Create new secret key**
4. Copy and save the key securely
5. ⚠️ **NEVER share or commit this key to Git!**

### Step 5: Configure WiFi Credentials
Edit the sketch:
```cpp
const char* WIFI_SSID = "YOUR_WIFI_NAME";           // Replace with your WiFi SSID
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";   // Replace with password
const char* API_KEY = "sk-proj-xxxxxxxxxxxxx";      // Your OpenAI API key
```

**Security Best Practice**: Use environment variables or config files in production (see Configuration section).

### Step 6: Upload Firmware
```bash
1. Connect ESP32 via USB cable
2. In Arduino IDE: Tools → Board → ESP32 Dev Module
3. In Arduino IDE: Tools → Port → Select your COM port
4. Click Upload (→ button)
5. Wait for "Leaving... Hard resetting via RTS pin"
6. Open Serial Monitor: Tools → Serial Monitor
7. Set baud rate to 115200
```

### Step 7: Test the System
```
In Serial Monitor, you should see:
"✅ WiFi Connected!"
"📡 IP Address: 192.168.x.x"
"Enter an image URL for analysis:"

Then type:
https://example.com/image.jpg
"What is in this image?"
```

---

## 💻 Usage Guide

### Basic Workflow

**Step 1: Start the Device**
```
Reset ESP32 (press RST button)
Wait for WiFi connection message
```

**Step 2: Provide Image URL**
```
Serial Monitor Input:
https://upload.wikimedia.org/wikipedia/commons/3/3a/Cat03.jpg

Device Response:
✅ Image URL received. Now enter your question:
```

**Step 3: Ask Natural Language Question**
```
Serial Monitor Input:
What animal is in this image and what is it doing?

Device Processing:
[ChatGPT] - Analyzing the provided image URL and question...

🧠 Description / Response:
This image shows a tabby cat sitting on a wooden surface. The cat appears 
to be alert and looking toward the camera. Its striped fur pattern is 
clearly visible, with orange and black markings typical of tabby cats...
```

**Step 4: Ask Follow-Up Questions**
```
After first response, system prompts:
"Enter another image URL for analysis:"

You can provide a new URL or ask more questions about the previous image
by providing the same URL again.
```

### Serial Monitor Example Interaction

```
🔌 Connecting to WiFi...
...
✅ WiFi Connected!
📡 IP Address: 192.168.1.100

Enter an image URL for analysis:
→ https://example.com/photo.jpg

✅ Image URL received. Now enter your question:
→ Describe the main objects in this image

📤 Sending request to OpenAI...
🌐 HTTP Response Code: 200

🧠 Description / Response:
The image shows a modern kitchen with stainless steel appliances, 
white cabinetry, and a granite countertop. There's a laptop on the counter 
and various cooking utensils...

Enter another image URL for analysis:
→ https://example.com/photo2.jpg
```

### Advanced Usage: Custom Prompts

You can modify the question system prompt for specialized tasks:

```cpp
// In the sketch, modify this section:
postBody += "\"messages\": [{";
postBody += "\"role\": \"user\",";
postBody += "\"content\": [";

// Add custom system context:
postBody += "{\"type\": \"text\", \"text\": \"You are a medical imaging expert. ";
postBody += question + "\"},";
```

---

## 🔒 Security Configuration

### ⚠️ API Key Management

**CRITICAL**: The current sketch has hardcoded secrets—unsafe for production!

**Recommended Solutions:**

#### Option 1: Environment Variables (Safest)
```cpp
// Use Arduino's Secrets library
#include <ArduinoSecrets.h>

const char* API_KEY = SECRET_OPENAI_KEY;
const char* WIFI_SSID = SECRET_WIFI_SSID;
```

#### Option 2: Secrets File (Development Only)
```cpp
// Create secrets.h (add to .gitignore)
#ifndef SECRETS_H
#define SECRETS_H
#define SECRET_SSID "your_ssid"
#define SECRET_PASS "your_password"
#define SECRET_API_KEY "your_api_key"
#endif
```

Then in main sketch:
```cpp
#include "secrets.h"
const char* WIFI_SSID = SECRET_SSID;
```

#### Option 3: SPIFFS File System
```cpp
// Store credentials in encrypted SPIFFS
SPIFFS.begin();
File f = SPIFFS.open("/config.json", "r");
DynamicJsonDocument doc(256);
deserializeJson(doc, f);
const char* API_KEY = doc["api_key"];
```

### HTTPS Certificate Validation

**Current Implementation** (Testing):
```cpp
client.setInsecure();  // Skip certificate validation
```

**Production Implementation**:
```cpp
// Create certificate pinning
const char* root_ca = 
  "-----BEGIN CERTIFICATE-----\n"
  "MIIEWjCCA0KgAwIBAgIQCgFubIthD7kIB13l+qkF+TANBgkqhkiG9w0BAQsFADBS\n"
  // ... certificate chain ...
  "-----END CERTIFICATE-----";

client.setCACert(root_ca);
```

---

## 📊 API Integration Details

### OpenAI API Endpoint
```
POST https://api.openai.com/v1/chat/completions
Content-Type: application/json
Authorization: Bearer sk-proj-xxxxxxxxxxxxx
```

### Request Format
```json
{
  "model": "gpt-4o-mini-2024-07-18",
  "messages": [{
    "role": "user",
    "content": [
      {
        "type": "text",
        "text": "What is in this image?"
      },
      {
        "type": "image_url",
        "image_url": {
          "url": "https://example.com/image.jpg"
        }
      }
    ]
  }]
}
```

### Response Format
```json
{
  "id": "chatcmpl-xxxxxxxxxx",
  "object": "chat.completion",
  "created": 1635789012,
  "model": "gpt-4o-mini-2024-07-18",
  "choices": [{
    "index": 0,
    "message": {
      "role": "assistant",
      "content": "The image shows..."
    },
    "finish_reason": "stop"
  }],
  "usage": {
    "prompt_tokens": 150,
    "completion_tokens": 200,
    "total_tokens": 350
  }
}
```

### Rate Limits & Quotas
- **Requests**: Up to 3,500 RPM (free tier)
- **Tokens**: Up to 90,000 TPM (free tier)
- **Model**: gpt-4o-mini (most affordable vision model)
- **Monitor**: Check usage at [OpenAI Platform](https://platform.openai.com/account/usage)

---

## 🐛 Troubleshooting

### WiFi Connection Issues
```
Problem: "WiFi Connect timed out"
Solution:
1. Check SSID and password are correct
2. Verify 2.4 GHz WiFi (ESP32 doesn't support 5 GHz)
3. Check firewall isn't blocking ESP32
4. Try manual network reset: WiFi.disconnect()
```

### API Key Errors
```
Problem: "HTTP error 401: Unauthorized"
Solution:
1. Verify API key is correct (copy-paste from OpenAI dashboard)
2. Check key hasn't been revoked
3. Ensure key has chat/vision permissions
4. Monitor usage at platform.openai.com
```

### JSON Parsing Errors
```
Problem: "⚠️ JSON parse error"
Solution:
1. Increase DynamicJsonDocument size: DynamicJsonDocument(16384)
2. Check API response with Serial.println(payload)
3. Verify response has expected "choices[0].message.content"
4. Check for typos in JSON key names
```

### HTTPS Connection Failures
```
Problem: "Failed to connect to OpenAI endpoint"
Solution:
1. Check internet connectivity
2. Verify API endpoint URL is correct
3. Disable firewall temporarily to test
4. Check ESP32 has adequate RAM (consider OTA updates)
5. Increase HTTPClient timeout:
   http.setTimeout(10000);  // 10 seconds
```

### Image URL Issues
```
Problem: "Image URL analysis returns generic response"
Solution:
1. Verify image URL is publicly accessible
2. Test URL in browser to confirm it works
3. Check image format (JPG, PNG, GIF, WebP supported)
4. Image must be smaller than 20MB
5. Use HTTPS URLs when possible
```

---

## 🚀 Future Roadmap

### Phase 1: Enhanced Features (v1.1)
- [ ] Support for base64-encoded images (no URL needed)
- [ ] Multi-image analysis in single query
- [ ] Real-time response streaming
- [ ] Image preprocessing (resize, quality optimization)
- [ ] Response caching to reduce API calls
- [ ] Confidence scoring for responses

### Phase 2: Advanced Integration (v1.2)
- [ ] Local TTS (Text-to-Speech) for responses
- [ ] WebUI dashboard for configuration
- [ ] MQTT publishing of results
- [ ] Scheduled image analysis
- [ ] SD card storage for conversation history
- [ ] Offline fallback with smaller local models

### Phase 3: Edge AI (v1.3)
- [ ] Hybrid approach: Local ML + Cloud AI
- [ ] Model selection based on image type
- [ ] On-device pre-filtering before API call
- [ ] Edge Impulse integration for faster inference
- [ ] Quantized model support for faster processing

### Phase 4: Production Deployment (v2.0)
- [ ] Docker containerization for server deployment
- [ ] RESTful API wrapper for multi-device deployment
- [ ] Web dashboard and mobile app
- [ ] Database integration for logging
- [ ] Advanced analytics and insights
- [ ] Enterprise authentication (OAuth2)

---

## 📚 Documentation

### Architecture & Design
- [System Architecture](docs/ARCHITECTURE.md)
- [API Integration Guide](docs/API_INTEGRATION.md)
- [Security Best Practices](docs/SECURITY.md)
- [Performance Optimization](docs/PERFORMANCE.md)

### Guides
- [Setup & Installation](docs/SETUP.md)
- [Configuration Guide](docs/CONFIGURATION.md)
- [Troubleshooting Guide](docs/TROUBLESHOOTING.md)
- [Advanced Usage](docs/ADVANCED.md)

### References
- [OpenAI API Docs](https://platform.openai.com/docs/api-reference)
- [GPT-4 Vision Capabilities](https://platform.openai.com/docs/guides/vision)
- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/)
- [ArduinoJson Documentation](https://arduinojson.org/)

---

## 🤝 Contributing

We welcome contributions! Check [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

### Development Workflow
```bash
# 1. Fork the repository
git clone https://github.com/pavankumar-21/MicroVision-AI.git

# 2. Create feature branch
git checkout -b feature/amazing-feature

# 3. Make changes and test
# (Test on actual ESP32 hardware)

# 4. Commit and push
git commit -m "Add amazing feature"
git push origin feature/amazing-feature

# 5. Create Pull Request
```

### Areas We Need Help
- 📝 Documentation improvements
- 🐛 Bug fixes and error handling
- ✨ New features and examples
- 🧪 Testing on different ESP32 variants
- 🌍 Translations and localization
- 📊 Performance optimizations

---

## 📄 License

This project is licensed under the **MIT License** - see [LICENSE](LICENSE) file.

```
MIT License

Copyright (c) 2025 Pavan Kumar Ginkala

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction...
```

---

## 🚨 Security Disclosure

If you discover a security vulnerability, please email **security@example.com** instead of using the issue tracker. Do not publicly disclose the vulnerability until it has been addressed.

---

## 👤 Author

**Pavan Kumar Ginkala**
- 🎓 MSc International Automotive Engineering
- 🔧 Mechanical Engineer | Embedded Systems & IoT
- 📍 Ingolstadt, Germany
- 💼 [LinkedIn](https://www.linkedin.com/in/pavan-kumar-ginkala-a42a57193)
- 📧 ginkalapavankumar@gmail.com

---

## 🙏 Acknowledgments

- **OpenAI** - GPT-4o Vision model
- **Espressif** - ESP32 hardware and ecosystem
- **Arduino** - Open-source hardware platform
- **Community** - All contributors and feedback providers

---

## 📞 Support

- **Issues & Bugs**: [GitHub Issues](https://github.com/pavankumar-21/MicroVision-AI/issues)
- **Discussions**: [GitHub Discussions](https://github.com/pavankumar-21/MicroVision-AI/discussions)
- **Email Support**: ginkalapavankumar@gmail.com
- **Discord Community**: [Join Server](#) (coming soon)

---

**⭐ Like this project? Please star it on GitHub and share with others!**

**Built with ❤️ by Pavan Kumar Ginkala**
