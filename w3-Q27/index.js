// index.js
const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};
