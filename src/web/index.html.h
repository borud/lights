static const char* INDEX_HTML PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <meta charset="UTF-8">
  <script src="/axios.min.js"></script>
  <style>
  body {
    background-color: #3F395B;
  }
	.slidecontainer {
	width: 100%;
	}
	
	.slider {
	-webkit-appearance: none;
	width: 100%;
	height: 60px;
	background: #E0E0FB;
	outline: none;
	opacity: 0.7;
	-webkit-transition: .2s;
	transition: opacity .2s;
	}
	
	.slider::-webkit-slider-thumb {
	-webkit-appearance: none;
	appearance: none;
	width: 60px;
	height: 60px;
	background: #E5E0FA;
	cursor: pointer;
    border-left: 2px solid #110934
    border-right: 2px solid #110934
	}

    #color-r { background: red; }
    #color-g { background: green; }
    #color-b { background: blue; }
    #color-w { background: white; }

	}
  </style>
</head>
<body>
  <div class="slidecontainer">
  <form>
	<input id="color-r" type="range" min="0" max="255" value="0" class="slider" onchange="colorChanged()">
	<input id="color-g" type="range" min="0" max="255" value="0" class="slider" onchange="colorChanged()">
	<input id="color-b" type="range" min="0" max="255" value="0" class="slider" onchange="colorChanged()">
	<input id="color-w" type="range" min="0" max="255" value="0" class="slider" onchange="colorChanged()">
  </form>
  </div>
  <span id="color-r-value"></span><span id="color-g-value"></span><span id="color-b-value"></span>&nbsp;<span id="color-w-value"></span>
<script>
  const apiUrl = "/rgbw";

  function colorChanged() {
    const color = this.getRGBW();
    setColor(color);

    axios.put(apiUrl, color).then((res) => {
      console.log("Success", res);
    }).catch((error) => {
      console.error(error);
    })

    console.log(color);
  }

  function getRGBW() {
    return {
      r: document.getElementById("color-r").value,
      g: document.getElementById("color-g").value,
      b: document.getElementById("color-b").value,
      w: document.getElementById("color-w").value
    };
  }
  
  function setColor(rgbw) {
    document.getElementById("color-r-value").innerText = hex(rgbw.r);
    document.getElementById("color-g-value").innerText = hex(rgbw.g);
    document.getElementById("color-b-value").innerText = hex(rgbw.b);
    document.getElementById("color-w-value").innerText = hex(rgbw.w);
    console.log(document.getElementById("color-r-value").innerText)
  }

  hex = function(number) {
    return (number < 10) ? "0" + Math.abs(number).toString(16) : Math.abs(number).toString(16);
  }
  
  setColor(getRGBW());
</script>
</body>
</html>
)=====";
