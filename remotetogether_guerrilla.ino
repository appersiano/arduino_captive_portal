#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const byte DNS_PORT = 53;
IPAddress apIP(192, 168, 4, 1);
DNSServer dnsServer;
WebServer server(80);

const char* ssid = "📍 Coworking segreto";

void handleRoot() {
  server.send(200, "text/html",
    "<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
    "<title>RemoteTogether.io</title>"
    "<style>"
    "body { margin: 0; font-family: -apple-system, BlinkMacSystemFont, sans-serif; color: #fff;"
    "display: flex; flex-direction: column; justify-content: space-between; align-items: center; height: 100vh; text-align: center; padding: 40px 20px 60px 20px; box-sizing: border-box;"
    "background: linear-gradient(120deg, #3a7bd5, #00d2ff);"
    "background-size: 400% 400%;"
    "animation: gradientShift 15s ease infinite; }"

    "main { display: flex; flex-direction: column; justify-content: center; align-items: center; flex-grow: 1; }"

    "h1, p, .subtext { opacity: 0; animation: fadeIn 1.5s ease-in-out forwards; }"
    "h1 { font-size: 2rem; margin-bottom: 1rem; animation-delay: 0.3s; }"
    ".subtext { font-size: 1rem; color: #f0f0f0; max-width: 400px; animation-delay: 0.7s; }"
    "p { font-size: 1.2rem; max-width: 400px; animation-delay: 1.2s; padding-bottom: 10px; }"

    "@keyframes fadeIn { from { opacity: 0; transform: translateY(20px); } to { opacity: 1; transform: translateY(0); } }"
    "@keyframes gradientShift { 0% {background-position: 0% 50%;} 50% {background-position: 100% 50%;} 100% {background-position: 0% 50%;} }"
    "</style>"

    "<script>"
    "document.addEventListener('DOMContentLoaded', function() {"
    "  const h1 = document.querySelector('h1');"
    "  const p = document.querySelector('p');"
    "  const sub = document.querySelector('.subtext');"
    "  const lang = navigator.language || navigator.userLanguage;"
    "  const isItalian = lang.startsWith('it');"

    "  const frasiIt = ["
    "    'Nessun segreto. Solo posti nuovi e persone interessanti da scoprire. Visita RemoteTogether.io.',"
    "    'Cerchi un posto dove lavorare e qualcuno con cui condividerlo? Scopri RemoteTogether.io.',"
    "    'Scopri nuovi spazi e incontra chi lavora da remoto nella tua città. Apri RemoteTogether.io.'"
    "  ];"

    "  const frasiEn = ["
    "    'No secrets. Just great places and great people waiting to be found. Discover them now at RemoteTogether.io.',"
    "    'Looking for new places to work and people to share your day with? Visit RemoteTogether.io.',"
    "    'Find new places to work and connect with remote people near you. Just open your browser and go to RemoteTogether.io.'"
    "  ];"

    "  const frase = isItalian ? frasiIt[Math.floor(Math.random() * frasiIt.length)] : frasiEn[Math.floor(Math.random() * frasiEn.length)];"

    "  h1.textContent = 'RemoteTogether.io';"
    "  p.innerHTML = isItalian ? 'Scopri di più aprendo il tuo browser e visitando <strong>RemoteTogether.io</strong>' : 'Learn more by opening your browser and visiting <strong>RemoteTogether.io</strong>';"
    "  sub.textContent = frase;"
    "});"
    "</script>"
    "</head><body>"

    "<main>"
    "<h1>...</h1>"
    "<div class='subtext'>...</div>"
    "</main>"
    "<p>...</p>"

    "</body></html>"
  );
}



void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  Serial.println("Access Point 'caffettino' avviato.");

  dnsServer.start(DNS_PORT, "*", apIP);

  server.onNotFound(handleRoot);
  server.begin();
  Serial.println("Server HTTP pronto.");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
