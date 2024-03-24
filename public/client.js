let localId;

const myVideo = document.createElement("video");
myVideo.muted = true;
//document.body.appendChild(myVideo);

let password = "",
  passwordCorrect = false;

navigator.mediaDevices.getDisplayMedia().then(stream => {
  // myVideo.srcObject = stream;
  // myVideo.onloadedmetadata = () => {
  //   myVideo.play();
  // }
  peer.on("call", (call) => {
    call.answer(stream);
    const vid = document.createElement("video");
    vid.id = "OtherVid"
    call.on("stream", s => {
      vid.muted = false;
      vid.srcObject = s;
      //vid.width = myVideo.width;
      //vid.height = myVideo.height;
      if (window.location.origin != "http://localhost:3000") {
        document.body.appendChild(vid);
        vid.onloadedmetadata = () => vid.play();
      }
    })
  })
  socket.on("user-connected", userId => {
    if (userId != localId) {
      const call = peer.call(userId, stream);
      const vid = document.createElement("video");
      call.on("stream", s => {
        vid.muted = false;
        vid.srcObject = s;

        document.body.appendChild(vid);
        vid.onloadedmetadata = () => vid.play();
      })
      call.on("close", () => {
        vid.remove();
      })
    }
  })
})

peer.on("open", id => {
  localId = id;
  socket.emit("loaded", ROOM_ID, id);
  //console.log(id);
})

let lastMouseSend = 0;
let lastMouseSendThreshold = 2;

window.onmousemove = function(e) {
  if (window.location.origin != "http://localhost:3000" && passwordCorrect) {
    lastMouseSend++;
    if (lastMouseSend > lastMouseSendThreshold) {
      lastMouseSend = 0;
      socket.emit("MouseMove", { x: e.x, y: e.y, password });
    }
  }
}

window.onmousedown = function (e) {
  let code = "dl";

  if (checkRightMB(e)) {
      code = "dr";
  }
  socket.emit("MouseClick", { code, password });
}
window.onmouseup = function (e) {
  let code = "ul";

  if (checkRightMB(e)) {
      code = "ur";
  }
  socket.emit("MouseClick", { code, password });
}

window.onkeydown = function(e) {
  e.preventDefault();
  socket.emit("KeyPress", { code: "d" + e.key, password });

  return e;
}

window.onkeyup = function(e) {
  e.preventDefault();
  socket.emit("KeyPress", { code: "u" + e.key, password });

  return e;
}

window.onload = function() {
  let attempt = prompt("Enter server access password");
  password = attempt;
  passwordCorrect = false;
  socket.emit("AttemptPassword", attempt, (correct) => {
    passwordCorrect = correct;
    if (correct) {
      alert("Correct password");
    } else {
      alert("Wrong password");
      window.location.reload();
    }
  });
}

function checkRightMB(event) {
  let isRightMB;

  if ("which" in event)  // Gecko (Firefox), WebKit (Safari/Chrome) & Opera
      isRightMB = event.which == 3;
  else if ("button" in event)  // IE, Opera 
      isRightMB = event.button == 2;

  return isRightMB;
}

document.oncontextmenu = function(e) {
  e.preventDefault();
  return e;
}