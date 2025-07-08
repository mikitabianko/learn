export class Graph {
  constructor(nodes, maxLengthOfVerge) {
    this.verges = [];
    this.maxLengthOfVerge = maxLengthOfVerge;
    this.update(nodes, maxLengthOfVerge);
  }
  draw(context) {
    for (let i = 0; i < this.verges.length; ++i) {
      context.beginPath();
      context.moveTo(this.verges[i].p1.x, this.verges[i].p1.y);
      context.lineTo(this.verges[i].p2.x, this.verges[i].p2.y);
      context.strokeStyle = "#FF00FF";
      context.stroke();
    }
  }
  update(nodes) {
    this.verges = [];
    for (let i = 0; i < nodes.length; ++i) {
      for (let j = i + 1; j < nodes.length; ++j) {
        if (
          Math.pow(nodes[i].x - nodes[j].x, 2) +
            Math.pow(nodes[i].y - nodes[j].y, 2) <
          this.maxLengthOfVerge * this.maxLengthOfVerge
        ) {
          this.verges.push({ p1: nodes[i], p2: nodes[j] });
        }
      }
    }
  }
}
