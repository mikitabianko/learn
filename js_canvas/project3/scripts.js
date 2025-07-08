import { launchFullScreen } from "./window.js";
import { setFullScreen, createCanvas, fillFullScreen } from "./canvas.js";
import { animation } from "./animations.js";
import { Circle } from "./circle.js";
import { Graph } from "./graph.js";
import { gravity } from "./Physics.js";

const canvas = createCanvas("app");
const context = canvas.getContext("2d");

const cfg = {
  count: 30,
  radius: 1,
  color: "#C51042",
  len: 100,//Math.max(window.innerHeight, window.innerWidth) / 1.2,
  G: .2,
};

const circles = [];

for (let i = 0; i < cfg.count; ++i) {
  let x = Math.random() * (window.innerWidth - 2 * cfg.radius) + cfg.radius;
  let y = Math.random() * (window.innerHeight - 2 * cfg.radius) + cfg.radius;
  let dx = (Math.random() - 0.5) * 3;
  let dy = (Math.random() - 0.5) * 3;

  let weight = Math.random() + 1;

  circles.push(new Circle(x, y, weight * cfg.radius, dx, dy, cfg.color, weight));
}
const graph = new Graph(
  circles.map((c) => {
    return {
      x: c.x,
      y: c.y,
    };
  }),
  cfg.len
);

animation({
  clear() {
    setFullScreen(canvas);
    fillFullScreen(context, "#3c3c3c");
  },
  update() {
    for (let i = 0; i < circles.length; ++i) { 
      circles[i].update();
    }
    graph.update(
      circles.map((c) => {
        return {
          x: c.x,
          y: c.y,
        };
      })
    );
    gravity(circles, cfg.G);
  },
  render() {
    for (let i = 0; i < circles.length; ++i) {
      circles[i].draw(context);
    }
    graph.draw(context, cfg.color);
  },
});

canvas.onclick = function () {
  launchFullScreen(document.body);
};
