const a = new Float32Array([1.0, 2.0, 3.0, 4.0, 5.0]);
const b = new Float32Array(3);
//fill array b from array a
for (let i = 0; i < 3; i++) {
    b[i] = a[i];
}
console.log(b);