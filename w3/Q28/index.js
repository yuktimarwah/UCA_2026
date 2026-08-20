const usersDiv = document.getElementById("users");

if (window.Worker) {
    const worker = new Worker("worker.js");

    worker.postMessage("fetchUsers");

    worker.onmessage = function (event) {
        const data = event.data;

        if (data.error) {
            usersDiv.textContent = data.error;
            return;
        }

        usersDiv.innerHTML = "";

        data.forEach(user => {
            const p = document.createElement("p");
            p.textContent = `${user.name} - ${user.active ? "Active" : "Inactive"}`;
            usersDiv.appendChild(p);
        });
    };

    worker.onerror = function () {
        usersDiv.textContent = "An error occurred while loading users.";
    };
} else {
    usersDiv.textContent = "Web Workers are not supported in this browser.";
}
