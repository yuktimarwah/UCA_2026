// worker.js
self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error(`HTTP Error: ${response.status}`);
        }

        const users = await response.json();

        if (!users || users.length === 0) {
            throw new Error("No users returned from the API.");
        }

        users.forEach(user => {
            console.log(`${user.name} - ${user.active ? "Active" : "Inactive"}`);
        });
    } catch (error) {
        console.error("Error:", error.message);
    }
};
