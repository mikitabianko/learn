import { launchFullScreen } from "./window.js";
import { setFullScreen, createCanvas, fillFullScreen } from "./canvas.js";
import { animation } from "./animations.js";
import { createMouse } from "./createMouse.js";
import { Circle } from "./circle.js";
import { Graph } from "./graph.js";
import { gravity } from "./Physics.js";

const canvas = createCanvas("app");
const context = canvas.getContext("2d");

const mouse = createMouse(canvas);

const cfg = {
  radius: 1,
  color: "#FF3B30",
  len: 100,
  G: 0.2,
  mouseWeight: 100,
};

const circles = [];

const graph = new Graph([], cfg.len);

animation({
  clear() {
    setFullScreen(canvas);
    fillFullScreen(context, "#3c3c3c");
  },
  update() {
    if (mouse.left && !mouse.pLeft) {
      circles.push(
        new Circle(mouse.x, mouse.y, cfg.radius, 0, 0, cfg.color, 1)
      );
    }

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

    if (mouse.middle && mouse.pMiddle) {
      gravity(
        [...circles, { x: mouse.x, y: mouse.y, weight: cfg.mouseWeight }],
        cfg.G
      );
    } 
    else {
      gravity(circles, cfg.G);
    }
    mouse.tick();
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
