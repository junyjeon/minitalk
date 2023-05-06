<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
minitalk
</h1>
<h3 align="center">📍 Say a lot with Minitalk!</h3>
<h3 align="center">🚀 Developed with the software and tools below.</h3>
<p align="center">

<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black" alt="" />
</p>

</div>

---
## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📍Overview](#-introdcution)
- [🔮 Features](#-features)
- [⚙️ Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🏎💨 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [🪪 License](#-license)
- [📫 Contact](#-contact)
- [🙏 Acknowledgments](#-acknowledgments)

---

## 📍Overview

Minitalk is a simple chat client built using Node.js and Socket.io. It allows for multiple users to connect to the same chat session, with messages sent to all participants.

## 🔮 Feautres

> `[📌  INSERT-PROJECT-FEATURES]`

---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-github-open.svg" width="80" />

## ⚙️ Project Structure

```bash
repo
├── Makefile
├── includes
│   └── minitalk.h
├── libft
├── srcs_client
│   └── client.c
└── srcs_server
    └── server.c

4 directories, 4 files
```
---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-src-open.svg" width="80" />

## 💻 Modules
<details closed><summary>Includes</summary>

| File       | Summary                                                                                                                                                                              | Module              |
|:-----------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:--------------------|
| minitalk.h | This code is a header file for a minitalk program , which is a client - server communication program . It includes the necessary libraries and header files for the program to run . | includes/minitalk.h |

</details>

<details closed><summary>Srcs_client</summary>

| File     | Summary                                                                                                                                                                                                                              | Module               |
|:---------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------|
| client.c | This code is a client program for a minitalk application . It takes in a pid and a string as arguments and sends the string to the server using signals . It includes error handling for invalid pid and wrong number of arguments . | srcs_client/client.c |

</details>

<details closed><summary>Srcs_server</summary>

| File     | Summary                                                                                                                                                                                                            | Module               |
|:---------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:---------------------|
| server.c | This code is a server program written in C that handles signals from a client program . It uses the sigaction ( ) function to set up a handler for the SIGUSR1 and SIGUSR2 signals , which it then uses to read in | srcs_server/server.c |

</details>
<hr />

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> `[📌  INSERT-PROJECT-PREREQUISITES]`

### 💻 Installation

1. Clone the minitalk repository:
```sh
git clone https://github.com/junyjeon/minitalk
```

2. Change to the project directory:
```sh
cd minitalk
```

3. Install the dependencies:
```sh
gcc -o myapp main.c
```

### 🤖 Using minitalk

```sh
./myapp
```

### 🧪 Running Tests
```sh
#run tests
```

<hr />

## 🛠 Future Development
- [X] [📌  COMPLETED-TASK]
- [ ] [📌  INSERT-TASK]
- [ ] [📌  INSERT-TASK]


---

## 🤝 Contributing
Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a pull request to the original repository.
Open a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary.
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 🪪 License

This project is licensed under the `[📌  INSERT-LICENSE-TYPE]` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 🙏 Acknowledgments

[📌  INSERT-DESCRIPTION]


---

