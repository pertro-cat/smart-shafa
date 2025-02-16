#ifndef INDEX_HTML_H
#define INDEX_HTML_H

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1" />
    <style>
      body {
        font-family: Arial;
        text-align: center;
        margin: 0px auto;
        padding-top: 30px;
      }

      .button {
        padding: 10px 20px;
        margin-bottom: 50px;
        font-size: 24px;
        text-align: center;
        outline: none;
        color: #fff;
        background-color: #2f4468;
        border: none;
        border-radius: 5px;
        box-shadow: 0 6px #999;
        cursor: pointer;
        -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
      }

      .button:hover {
        background-color: #1f2e45;
      }

      .button:active {
        background-color: #1f2e45;
        box-shadow: 0 4px #666;
        transform: translateY(2px);
      }

      .input1 {
        margin-bottom: 30px;
        padding: 6px 12px;
        font-size: 16px;
        font-weight: 700;
        line-height: 1.5;
        color: #212529;
        background-color: #fff;
        background-clip: padding-box;
        border: 1px solid #ced4da;
        appearance: none;
        border-radius: 4px;
        transition: border-color 0.15s ease-in-out, box-shadow 0.15s ease-in-out;
      }

      .label1 {
        font-size: 28px;
      }

      .custom_margin {
        padding-bottom: 30px;
      }

      @media screen and (max-width: 480px) {
        .button {
          padding: 15px 100px 15px 10px;
          font-size: 10px;
        }

        h1 {
          font-size: 24px;
          padding-top: 20px;
        }
      }
    </style>
  </head>

  <body>
    <h1>шафа в нарнію</h1>
    <h2>enter wifi data</h2>
    <div id="wifiData">
      <div>
        <label for="ssidInput" class="label1">
          ssid <label id="ssidLabel"></label>:
        </label>
        <input class="input1" id="ssidInput" />
      </div>
      <div>
        <label for="passwordInput" class="password">
          password <label id="passwordLabel"></label>:
        </label>
        <input class="input1" id="passwordInput" />
      </div>

      <button class="button" onclick="sendWiFiData()">Confirm</button>
    </div>

    <h2>Enter pin for unlock</h2>
    <div>
      <label for="pin" class="pin"> pin <label id="pin"></label>: </label>
      <input class="input1" id="pinInput" />
      <button class="button" onclick="sendPin()">Unlock</button>
    </div>

    <div>
      <button class="button" id="backlight" onclick="backlight();">
        Do you want to turn on backlight - <span id="backlightStatus">yes</span>
      </button>
    </div>

    <script>
      function sendWiFiData() {
        var ssid = document.getElementById("ssidInput").value.trim();
        var password = document.getElementById("passwordInput").value.trim();

        if (!ssid) {
          alert("SSID cannot be empty!");
          return;
        }
        if (!password) {
          alert("Password cannot be empty!");
          return;
        }

        var xhr = new XMLHttpRequest();
        xhr.open(
          "GET",
          `/?ssid=${encodeURIComponent(ssid)}&password=${encodeURIComponent(
            password
          )}`,
          true
        );
        xhr.send();

        console.log("ass");
        console.log(ssid, ",", password);
      }

      function sendPin() {
        var pin = document.getElementById("pinInput").value.trim();

        if (!pin) {
          alert("PIN cannot be empty!");
          return;
        }

        var xhr = new XMLHttpRequest();
        xhr.open("GET", `/?pin=${encodeURIComponent(pin)}`, true);
        xhr.send();

        console.log("yep");
        console.log(pin);
      }

      function backlight() {
        var backlightStatus = document.getElementById("backlightStatus");
        var xhr = new XMLHttpRequest();
        xhr.open("GET", "/", true);
        xhr.send();

        if (backlightStatus.textContent === "yes") {
          xhr.open("GET", "/backlight_false", true);
          xhr.send();
          backlightStatus.textContent = "no";
        } else {
          xhr.open("GET", "/backlight_true", true);
          xhr.send();
          backlightStatus.textContent = "yes";
        }
        console.log("ddd");
      }
    </script>
  </body>
</html>

)rawliteral";

#endif // INDEX_HTML_H