export class Circle {
  constructor(x, y, radius, dx, dy, color) {
    this.x = x;
    this.y = y;
    this.radius = radius;
    this.dx = dx;
    this.dy = dy;
    this.color = color;
  }
  draw(context) {
    context.beginPath();
    context.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
    context.strokeStyle = this.color;
    context.fillStyle = this.color;
    context.fill();
    context.stroke();
  }
  update() {
    if (
      this.x + this.dx + this.radius >= window.innerWidth ||
      this.x + this.dx - this.radius <= 0
    ) {
      this.dx = -this.dx;
    }

    if (
      this.y + this.dy + this.radius >= window.innerHeight ||
      this.y + this.dy - this.radius <= 0
    ) {
      this.dy = -this.dy;
    }

    if (
      this.x + this.radius > window.innerWidth ||
      this.y + this.radius > window.innerHeight ||
      this.x - this.radius < 0 ||
      this.y - this.radius < 0
    ) {
      this.x =
        Math.random() * (window.innerWidth - 2 * this.radius) + this.radius;
      this.y =
        Math.random() * (window.innerHeight - 2 * this.radius) + this.radius;
      return;
    }
    this.x += this.dx;
    this.y += this.dy;
  }
}
