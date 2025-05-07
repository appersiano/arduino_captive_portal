# Arduino Captive Portal for Guerrilla Marketing via WiFi

This project demonstrates how to create a simple captive portal using an Arduino-compatible board with WiFi capabilities (e.g. ESP8266 or ESP32). The goal is to use this captive portal as a tool for guerrilla marketing, displaying custom promotional messages when users connect to your open WiFi network.

## 📡 What Is a Captive Portal?

A captive portal is a web page that is shown to users before they can access the internet—commonly seen in public WiFi networks (like airports or cafes). In this project, we leverage this concept to display marketing content (e.g. a campaign slogan, link, or visual asset) as soon as someone connects to your WiFi network.

## 🎯 Use Case
This project is ideal for:
-	Street marketing campaigns
-	Conferences, meetups, or events
-	Product promotions in public spaces
-	Creative networking ideas

 Example: set up a small hotspot in a park, and people who connect to the WiFi see your landing page with a catchy message like “We’re Hiring!” or “Claim Your Free Coffee!”

## 🚀 Features
-	Creates an open WiFi access point with a custom SSID
-	Automatically redirects connected devices to a local landing page
-	Customizable HTML content
-	No internet connection required
-	Lightweight and self-contained

## 🛠️ Hardware Requirements

-	ESP8266 or ESP32 development board (e.g. NodeMCU, Wemos D1 Mini, etc.)
-	Micro-USB cable
-	Arduino IDE installed

 ## 📦 Installation & Setup
1.	Clone the repository:
<pre lang="bash">
 git clone https://github.com/appersiano/arduino_captive_portal.git
</pre>

2.	Install dependencies in Arduino IDE:
 
	-	Install the ESP8266 or ESP32 board support via Board Manager
	-	Install the required libraries:
	-	ESPAsyncWebServer
	-	DNSServer

3.	Configure your settings:
Open the `remotetogether_guerrilla.ino` file and set:

<pre lang="cpp">
const char* ssid = "Your_WiFi_Name";

void handleRoot() {
  server.send(200, "text/html","put HTML code here")
}
</pre>

4.	Upload the code:
Connect your board via USB, select the correct board and port, then upload.

5.	Deploy:
Place the board in a visible area with power (e.g. a power bank) and start collecting attention.


## 🌐 How It Works
-	The board starts an open access point with the SSID you define.
-	It sets up a DNS server to redirect all domain requests to the local IP.
-	It serves a simple HTML page stored in memory or SPIFFS.
-	As soon as someone connects and opens a browser, they are redirected to your marketing message.

## 🔒 Ethical Considerations

Be respectful of local laws and public space policies. Always include a way for users to opt out or leave the captive portal. This project is intended for creative, ethical use only.

## 📷 Demo
![5825492507432174019](https://github.com/user-attachments/assets/f03bdf32-d559-45c7-b08f-bf7ba5fca9c1)
![5825492507432174018](https://github.com/user-attachments/assets/4083ed1b-cb26-4ca3-963b-945439057c69)


Insert screenshot or photo of the setup and landing page here (optional).

## ✏️ Customization Ideas
-	Use CSS or images to style your landing page
-	Add clickable links to your site, QR codes, or contact info
-	Serve different content based on time or event type

## 🤝 Contributing

Pull requests and suggestions are welcome! If you have ideas for improvements or want to share your creative use case, feel free to contribute.

## 📄 License

MIT License. See LICENSE for more information.
