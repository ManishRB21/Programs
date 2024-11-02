LlD of a tic tac toe
Features Required:

Initialization: Ability to initialize a new game.
Move Validation: Check if a move is valid.
Board Update: Update the board with the player's move.
Win Condition: Check for a win condition.
Draw Condition: Check for a draw condition.
Player Switching: Switch between players after each move.
Design Patterns Involved:

Singleton Pattern: To ensure there is only one instance of the game controller.
Factory Pattern: To create player instances.
Observer Pattern: To notify players of the game state changes.
Strategy Pattern: To encapsulate the algorithm for move validation and win/draw condition checking in js

Here's a **Low-Level Design (LLD)** for a **Tic Tac Toe** game, incorporating the required features and design patterns.

### 1. **Class Diagram:**

```
+--------------------+           +---------------------+
|   GameController   | <--------> |      Player         |
+--------------------+           +---------------------+
| - instance         |           | - name              |
| - board: Board     |           | - symbol            |
| - currentPlayer    |           |                     |
+--------------------+           +---------------------+
| + initialize()     |           | + makeMove()        |
| + playMove()       |           +---------------------+
| + switchPlayer()   |           | << Factory Pattern >>|
| + checkWin()       |                                  |
| + checkDraw()      |                                  |
+--------------------+                                  |
  << Singleton Pattern >>                               |
+--------------------+           +---------------------+
|       Board        |           |    GameObserver      |
+--------------------+           +---------------------+
| - cells: 3x3 grid  |           | - state             |
+--------------------+           |                     |
| + updateBoard()    |           | + update()          |
| + displayBoard()   |           +---------------------+
+--------------------+           | << Observer Pattern >>|
  << Strategy Pattern >>
```

### 2. **Class Breakdown:**

#### **GameController (Singleton Pattern)**
This class is responsible for controlling the game, switching players, validating moves, and checking win/draw conditions. 

- **Attributes:**
  - `instance`: Ensures only one instance of `GameController` exists.
  - `board`: A `Board` object representing the current game board.
  - `currentPlayer`: The player whose turn it is to play.

- **Methods:**
  - `initialize()`: Initializes a new game, creating players and resetting the board.
  - `playMove(row, col)`: Validates and processes the player’s move.
  - `switchPlayer()`: Switches between the two players.
  - `checkWin()`: Checks if the current move resulted in a win.
  - `checkDraw()`: Checks if the game is a draw.
  
  **Singleton Pattern:** This ensures there's only one game controller managing the game flow.

#### **Player (Factory Pattern)**
This class represents the player. The factory pattern can be used to create player instances, which can be either human or AI players.

- **Attributes:**
  - `name`: The name of the player.
  - `symbol`: The player's symbol, either `X` or `O`.
  
- **Methods:**
  - `makeMove(row, col)`: Allows the player to make a move on the board.
  
  **Factory Pattern:** A factory can be used to instantiate players dynamically, based on the input type (e.g., human or AI).

#### **Board (Strategy Pattern)**
The board manages the 3x3 grid and updates itself when a move is made.

- **Attributes:**
  - `cells`: A 2D array representing the 3x3 board.

- **Methods:**
  - `updateBoard(row, col, symbol)`: Updates the board with the player's move.
  - `displayBoard()`: Prints the current state of the board.
  
  **Strategy Pattern:** Encapsulates the logic for validating moves and checking for win/draw conditions.

#### **GameObserver (Observer Pattern)**
The observer class is used to notify players of the state of the game. Each player is registered as an observer, and they are updated on game state changes (win, draw, invalid move).

- **Attributes:**
  - `state`: Stores the state of the game (e.g., ongoing, won, draw).

- **Methods:**
  - `update(state)`: Notifies players of game state changes.

  **Observer Pattern:** Allows multiple players to subscribe to game state changes and receive updates in real time.

### 3. **Sequence Diagram:**

**Play Move Sequence:**
```
Player               GameController           Board               GameObserver
   |                       |                     |                       |
   |----makeMove()--------->|                     |                       |
   |                        |----playMove()------>|                       |
   |                        |                     |---updateBoard()------>|
   |                        |                     |                       |
   |                        |<----moveValid-------|                       |
   |                        |-----checkWin()----->|                       |
   |                        |<----checkDraw()---->|                       |
   |                        |---notifyObservers-->|                       |
   |<--switchPlayer()------- |                     |                       |
```

### 4. **Design Patterns Involved:**

1. **Singleton Pattern** (`GameController`):
   - Ensures only one game controller is created to manage the game.

2. **Factory Pattern** (`Player`):
   - Allows for dynamic creation of player instances, such as human or AI players.

3. **Observer Pattern** (`GameObserver`):
   - Players are notified of the game’s state (win, draw, or ongoing) through the observer pattern.

4. **Strategy Pattern** (`Board`):
   - Encapsulates different algorithms (move validation, win/draw conditions) to keep the board’s logic flexible.

### 5. **Code Example:**

```js
// Singleton: GameController
class GameController {
  static instance = null;
  
  constructor() {
    if (GameController.instance) return GameController.instance;
    this.board = new Board();
    this.currentPlayer = null;
    this.players = [];
    GameController.instance = this;
  }

  static getInstance() {
    if (!GameController.instance) {
      GameController.instance = new GameController();
    }
    return GameController.instance;
  }

  initialize(players) {
    this.players = players;
    this.currentPlayer = this.players[0];
    this.board.displayBoard();
  }

  playMove(row, col) {
    if (!this.board.isValidMove(row, col)) {
      console.log("Invalid Move!");
      return;
    }
    
    this.board.updateBoard(row, col, this.currentPlayer.symbol);
    if (this.checkWin()) {
      console.log(`${this.currentPlayer.name} wins!`);
    } else if (this.checkDraw()) {
      console.log("It's a draw!");
    } else {
      this.switchPlayer();
    }
  }

  checkWin() { /* strategy logic */ }

  checkDraw() { /* strategy logic */ }

  switchPlayer() {
    this.currentPlayer = (this.currentPlayer === this.players[0]) ? this.players[1] : this.players[0];
  }
}

// Factory: Player
class Player {
  constructor(name, symbol) {
    this.name = name;
    this.symbol = symbol;
  }

  makeMove(row, col) {
    GameController.getInstance().playMove(row, col);
  }
}

// Strategy: Board
class Board {
  constructor() {
    this.cells = Array(3).fill().map(() => Array(3).fill(null));
  }

  isValidMove(row, col) {
    return this.cells[row][col] === null;
  }

  updateBoard(row, col, symbol) {
    this.cells[row][col] = symbol;
    this.displayBoard();
  }

  displayBoard() {
    console.log(this.cells);
  }
}

// Observer: GameObserver
class GameObserver {
  update(state) {
    console.log("Game state changed:", state);
  }
}
```

This design provides scalability and flexibility while adhering to important software engineering principles. Let me know if you need more details on any part!
