export class Graph {
  constructor(nodes, maxLengthOfVerge) {
    this.verges = [];
    this.maxLengthOfVerge = maxLengthOfVerge;
    this.update(nodes, maxLengthOfVerge);
  }
  draw(context, color) {
    for (let i = 0; i < this.verges.length; ++i) {
      context.beginPath();
      context.moveTo(this.verges[i].p1.x, this.verges[i].p1.y);
      context.lineTo(this.verges[i].p2.x, this.verges[i].p2.y);
      context.strokeStyle = color;
      context.lineWidth =
        -this.#distance(this.verges[i].p1, this.verges[i].p2) *
          Math.tan(3 / (this.maxLengthOfVerge * 1.25)) + 3;
      context.stroke();
    }
  }
  update(nodes) {
    this.verges = [];
    for (let i = 0; i < nodes.length; ++i) {
      for (let j = i + 1; j < nodes.length; ++j) {
        if (this.#distance(nodes[i], nodes[j]) < this.maxLengthOfVerge) {
          this.verges.push({ p1: nodes[i], p2: nodes[j] });
        }
      }
    }
  }
  #distance(p1, p2) {
    return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
  }
}
