# C++ File Operations and Automation Tools

This repository contains two utilities written in C++: **`cfile`** and **`crun`**. These tools allow you to perform file operations and automate the execution of commands with ease.

## Tools Overview

- **`cfile`**: A utility to interact with files by writing content to them.
- **`crun`**: A utility that reads a `.crun` file and automates the execution of commands listed inside it.

---

## Table of Contents

1. [`cfile` Usage](#cfile-usage)
2. [`crun` Usage](#crun-usage)
3. [Examples](#examples)
4. [Additional Notes](#additional-notes)

---

## `cfile` Usage

The **`cfile`** utility allows you to write content to a specified file. You can specify the file's name, the operation (writing), and the content to write.

### Syntax

```bash
cfile <file_name> <command : -w> <code : your_code>
```

### Arguments:

- **`<file_name>`**: The path to the file you want to interact with. This can be a relative or absolute path.
- **`<command>`**: The operation you want to perform. The only available command is:

  - **`-w`**: Write the specified content to the file.

- **`<code>`**: The content or code you want to write to the file (used with `-w`).

### Example 1: Writing to a File

To write the string `"hello"` into a file named `file.txt`:

```bash
cfile file.txt -w "hello"
```

This will create (or overwrite) `file.txt` and write `"hello"` to it.

### Example 2: Writing to a File with a Relative Path

You can also specify a file with a relative path:

```bash
cfile ./src/file.txt -w "hello"
```

This will write `"hello"` into `file.txt` located in the `./src/` directory.

---

## `crun` Usage

The **`crun`** utility allows you to automate the execution of multiple commands listed in a `.crun` file.

### How It Works

1. Create a `.crun` file and specify one or more commands (e.g., `node .`, `python main.py`, etc.).
2. Run **`crun`** to execute the commands in sequence.

### Example 1: Creating a `.crun` File

Let's create a `.crun` file called `run.crun` that contains the following commands:

```
node .
python main.py
```

### Example 2: Running the `.crun` File

To execute the commands in the `run.crun` file, simply run:

```bash
crun ./run.crun
```

This will sequentially execute the commands listed in the file (e.g., `node .` and `python main.py`).

---

## Examples

### Example 1: Writing to a File with `cfile`

```bash
cfile file.txt -w "This is an example text."
```

This will write `"This is an example text."` into `file.txt`.

### Example 2: Automating Command Execution with `crun`

1. Create a `.crun` file named `commands.crun`:

   ```
   node .
   python main.py
   ```

2. Run the following command to execute both commands:

   ```bash
   crun ./commands.crun
   ```

---

## Additional Notes

- **For `cfile`**:

  - If the file does not exist, `cfile` will create it.
  - If the file already exists, using `-w` will overwrite its content with the new code.

- **For `crun`**:

  - Make sure the commands in the `.crun` file are executable (e.g., `node`, `python`, etc.).
  - You can specify any valid shell command in the `.crun` file.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
