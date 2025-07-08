export function createCanvas(id) {
  const canvas = document.createElement("canvas");
  document.getElementById(id).appendChild(canvas);

  return document.querySelector("canvas");
}

export function setFullScreen(canvas) {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
}

export function clearFullScreen(context) {
  context.fillStyle = "#FFFFFF";
  context.fillRect(0, 0, window.innerWidth, window.innerHeight);
}
