const { exec } = require('child_process');
const express = require("express");
const app = express();
const PORT = 3000;
const io = require("socket.io")(app.listen(PORT, () => {
  console.log("Server listening on port " + PORT);
  exec("start chrome.exe http://localhost:" + PORT, (err, stdout, stderr) => {
    if (err) {
      console.log("Error opening browser");
    } else {
      console.log(stdout);
    }
  })
}));

let password = uid(4);
console.log("SERVER ACCESS PASSWORD: " + password);

app.set("view engine", "ejs");
app.use(express.static("public"));

app.get("/", (req, res) => {
  res.redirect("/" + "cfqi");//uid(4));
})
app.get("/:room", (req, res) => {
  res.render("room", { roomId: req.params.room })
})

io.on("connection", (socket) => {
  socket.on("loaded", (roomId, userId) => {
    socket.join(roomId);
    console.log("Joined room " + roomId + " with peer id " + userId);
    io.to(roomId).emit("user-connected", userId);
  })

  socket.on("AttemptPassword", (pass, callback) => {
    if (checkPassword(pass, password)) callback(true);
    else callback(false);
  })

  socket.on("MouseMove", (mouseData) => {
    if (checkPassword(mouseData.password, password)) {
      exec("cd libs & MoveMouseJSLib.exe " + mouseData.x + " " + mouseData.y, (err, stdout, stderr) => {
        if (err) {
          console.log("Error moving mouse");
        }
      })
    }
  })

  socket.on("MouseClick", (clickData) => {
    if (checkPassword(clickData.password, password)) {
      exec("cd libs & MouseClickJSLib.exe " + clickData.code, (err, stdout, stderr) => {
        if (err) {
          console.log("Error click mouse");
        }
      })
    }
  })

  socket.on("KeyPress", (keyData) => {
    if (checkPassword(keyData.password, password)) {
      exec("cd libs & KeyPressJSLib.exe " + keyData.code, (err, stdout, stderr) => {
        if (err) {
          console.log("Error pressing key");
        }
      })
    }
  })
})

function uid(length) {
  let chars = "qwertyuiopasdfghjklzxcvbnm";
  let id = '';
  for(let i = 0; i < length; i++) {
    id += chars.charAt(Math.floor(Math.random() * chars.length))
  }
  return id;
}

function checkPassword(input, realPass) {
  if (input == realPass) return true;
  return false;
}