# MiniTalk - A Signal-Based Communication Project

Welcome to **MiniTalk**! Ever wanted to send messages between processes using UNIX signals? This project is here to prove that communication doesn't need complex protocols; sometimes, it's just about signals and a bit of ingenuity.

## 🛠️ Project Overview

MiniTalk is made up of two components:

- **Client**: The sender of messages. It breaks the message into bits and transmits each bit using `kill()` and `SIGUSR1`/`SIGUSR2` signals.
- **Server**: The receiver that listens for signals and reconstructs the original message, printing it out when complete.

**Why did I do it?** To show that even the simplest signals can carry the deepest conversations.

## ⚙️ How It Works

### The Client:
- Takes the server's PID and a message as arguments.
- Encodes the message into bits and sends them as signals.
- Uses `usleep()` to control the timing between transmissions for reliability.

### The Server:
- Runs indefinitely, listening for `SIGUSR1` (bit `1`) and `SIGUSR2` (bit `0`).
- Reconstructs the incoming bits into a character and builds the complete message.
- Prints the decoded message when it receives a full byte.

## 🚀 Quick Start

1. **Compile the code** and create the executables:
   - make

2. **Start the server**:
   - Run `./server` to start listening for messages.

3. **Send a message** from the client:
   - Run `./client <PID> "Hello, MiniTalk!"`

**Pro Tip**: Replace `<PID>` with the actual process ID of the server.

## 🌟 Features

- **Low-Level Signal Communication**: Perfect for demonstrating how signals work at a basic level.
- **Dynamic Message Handling**: Translates signals into bits and reconstructs them in real time.
- **Minimalist and Efficient**: No bulky libraries, just plain old C and system calls.

## 🤔 Why Use This?

This project is perfect for:

- **Learning** how processes communicate in UNIX.
- **Experimenting** with low-level signal handling.
- **Impressing** your friends with how data can be sent with nothing but signals.

## 🚧 Limitations

- **Not Production-Ready**: While fun, it's not built for high reliability or security.
- **Timing Issues**: Signal delivery timing may vary based on system load.
- **Error Handling**: Minimal at best. A few more checks wouldn't hurt.

## 🎉 Fun Fact

This project was built to remind us that sometimes, "Hello" is just a few bits away. And also, `SIGKILL` isn’t invited to this party—no need for drama!

---

