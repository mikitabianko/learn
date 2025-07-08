import { launchFullScreen } from "./window.js";
import { setFullScreen, createCanvas, clearFullScreen } from "./canvas.js";
import { animation } from "./animations.js";
import { Circle } from "./circle.js";
import { Graph } from "./graph.js";

const canvas = createCanvas("app");
const context = canvas.getContext("2d");

const colors = [
  "#E32636",
  "#78DBE2",
  "#44944A",
  "#DE4C8A",
  "#7CFC00",
  "#FF00FF",
  "#FF69B4",
];

var circles = [];

for (let i = 0; i < 100; ++i) {
  let radius = 3;
  let x = Math.random() * (window.innerWidth - 2 * radius) + radius;
  let y = Math.random() * (window.innerHeight - 2 * radius) + radius;
  let dx = (Math.random() - 0.5) * 3;
  let dy = (Math.random() - 0.5) * 3;

  let rId = Math.floor(Math.random() * colors.length);
  circles.push(new Circle(x, y, radius, dx, dy, colors[rId]));
}

console.log(circles);

const graph = new Graph(
  circles.map((data) => {
    return { x: data.x, y: data.y };
  }),
  100
);

animation({
  clear() {
    setFullScreen(canvas);
    clearFullScreen(context);
  },
  update() {
    for (let i = 0; i < circles.length; ++i) {
      circles[i].update();
    }
    graph.update(
      circles.map((data) => {
        return { x: data.x, y: data.y };
      })
    );
  },
  render() {
    for (let i = 0; i < circles.length; ++i) {
      circles[i].draw(context);
    }
    graph.draw(context);
  },
});

canvas.onclick = function () {
  launchFullScreen(document.body);
};
