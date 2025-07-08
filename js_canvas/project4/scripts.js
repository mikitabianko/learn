import { launchFullScreen } from "./window.js";
import { setFullScreen, createCanvas, fillFullScreen } from "./canvas.js";
import { animation } from "./animations.js";

const canvas = createCanvas("app");
const context = canvas.getContext("2d");

main();

async function main() {
  const logo = await loadImage("img/logo.jpg");

  animation({
      clear() {
        setFullScreen(canvas);
        fillFullScreen(context, "#3c3c3c");
      },
      update() {
        
      },
      render() {
        context.drawImage(logo, 0, 0);
      },
  });
}

function loadImage(src) {
	return new Promise((resolve) => {
		const image = new Image();
		image.src = src;
		image.onload = () => resolve(image);
	});
}

canvas.onclick = function () {
  launchFullScreen(document.body);
};
