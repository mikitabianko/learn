import { launchFullScreen, setFullScreen, createCanvas, clearFullScreen } from "./canvas.js";
import { animation } from "./animations.js";
import { Circle } from "./circle.js";

const canvas = createCanvas("app");
const context = canvas.getContext("2d");

var circles = [];

const colors = [
    "#E32636",
    "#78DBE2",
    "#44944A",
    "#DE4C8A",
    "#7CFC00",
    "#FF00FF",
    "#FF69B4"
];

for (let i = 0; i < 100; ++i) {
  let radius = 15;
  let x = Math.random() * (window.innerWidth - 2 * radius) + radius;
  let y = Math.random() * (window.innerHeight - 2 * radius) + radius;
  let dx = (Math.random() - 0.5) * 10;
  let dy = (Math.random() - 0.5) * 10;

  let rId = Math.floor(Math.random() * colors.length);
  circles.push(new Circle(x, y, radius, dx, dy, colors[rId]));
}

animation({
  clear() {
    clearFullScreen(context);
  },
  update() {
    setFullScreen(canvas);
  },
  render() {
    for (let i = 0; i < circles.length; ++i) {
      circles[i].draw(context);
    }
  },
});

canvas.onclick = function () {
  launchFullScreen(document.body);
};