export function gravity(objects, G) {
  for (let i = 0; i < objects.length; ++i) {
    for (let j = i + 1; j < objects.length; ++j) {
      a(G, objects[i], objects[j]);
    }
  }
}

function distance(p1, p2) {
  return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
}

function a(G, obj1, obj2) {
  const v = {
    x: obj1.x - obj2.x,
    y: obj1.y - obj2.y,
  };

  const size = distance(obj1, obj2);

  const f = (obj1.weight * obj2.weight * G) / Math.pow(size, 2);

  v.x *= f;
  v.y *= f;

  obj1.dx -= v.x / obj1.weight;
  obj1.dy -= v.y / obj1.weight;

  obj2.dx += v.x / obj2.weight;
  obj2.dy += v.y / obj2.weight;
}
