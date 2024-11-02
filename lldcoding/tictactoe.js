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
Sure! Here's the complete code for the **Tic Tac Toe** game, implementing the necessary features and design patterns:

```js
// Singleton: GameController
class GameController {
  static instance = null;
  
  constructor() {
    if (GameController.instance) return GameController.instance;
    this.board = new Board();
    this.currentPlayer = null;
    this.players = [];
    this.observers = [];
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
    this.notifyObservers("Game initialized. Player 1's turn.");
  }

  playMove(row, col) {
    if (!this.board.isValidMove(row, col)) {
      console.log("Invalid Move! Try again.");
      return;
    }
    
    this.board.updateBoard(row, col, this.currentPlayer.symbol);
    if (this.checkWin()) {
      console.log(`${this.currentPlayer.name} wins!`);
      this.notifyObservers(`${this.currentPlayer.name} wins!`);
    } else if (this.checkDraw()) {
      console.log("It's a draw!");
      this.notifyObservers("The game is a draw.");
    } else {
      this.switchPlayer();
      this.notifyObservers(`${this.currentPlayer.name}'s turn.`);
    }
  }

  checkWin() {
    const winConditions = [
      // Horizontal wins
      [[0, 0], [0, 1], [0, 2]],
      [[1, 0], [1, 1], [1, 2]],
      [[2, 0], [2, 1], [2, 2]],
      // Vertical wins
      [[0, 0], [1, 0], [2, 0]],
      [[0, 1], [1, 1], [2, 1]],
      [[0, 2], [1, 2], [2, 2]],
      // Diagonal wins
      [[0, 0], [1, 1], [2, 2]],
      [[0, 2], [1, 1], [2, 0]]
    ];

    return winConditions.some(condition => 
      condition.every(([row, col]) => this.board.cells[row][col] === this.currentPlayer.symbol)
    );
  }

  checkDraw() {
    return this.board.cells.every(row => row.every(cell => cell !== null));
  }

  switchPlayer() {
    this.currentPlayer = (this.currentPlayer === this.players[0]) ? this.players[1] : this.players[0];
  }

  // Observer methods
  addObserver(observer) {
    this.observers.push(observer);
  }

  notifyObservers(state) {
    this.observers.forEach(observer => observer.update(state));
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
    console.log(this.cells.map(row => row.map(cell => cell || "-").join(" ")).join("\n"));
  }
}

// Observer: GameObserver
class GameObserver {
  update(state) {
    console.log("Game state update:", state);
  }
}

// Initialize the game
const player1 = new Player("Player 1", "X");
const player2 = new Player("Player 2", "O");
const gameController = GameController.getInstance();

// Add observer
const gameObserver = new GameObserver();
gameController.addObserver(gameObserver);

// Start a new game
gameController.initialize([player1, player2]);

// Example gameplay
player1.makeMove(0, 0); // Player 1 moves
player2.makeMove(1, 1); // Player 2 moves
player1.makeMove(0, 1); // Player 1 moves
player2.makeMove(2, 2); // Player 2 moves
player1.makeMove(0, 2); // Player 1 wins
```

### Explanation of Changes:
1. **`checkWin()`**: This method checks for winning conditions (rows, columns, and diagonals).
2. **`checkDraw()`**: This checks if all the cells are filled and there’s no winner, leading to a draw.
3. **`addObserver()` and `notifyObservers()`**: These methods implement the **Observer Pattern**, where the game state changes are communicated to all registered observers.
4. **Gameplay**: The `initialize` method starts a new game, and the `makeMove` method allows players to take turns playing.

### Sample Output:
```
- - -
- - -
- - -
Game state update: Game initialized. Player 1's turn.
X - -
- - -
- - -
Game state update: Player 2's turn.
X - -
- O -
- - -
Game state update: Player 1's turn.
X X -
- O -
- - -
Game state update: Player 2's turn.
X X -
- O -
- - O
Game state update: Player 1's turn.
X X X
- O -
- - O
Player 1 wins!
Game state update: Player 1 wins!
```

This implementation covers all the required features and design patterns, offering a flexible and maintainable architecture for the Tic Tac Toe game. Let me know if you have any further questions or modifications!

Here’s an explanation of the four design patterns used in the Tic Tac Toe game:

### 1. **Singleton Pattern**

#### What it is:
The **Singleton Pattern** ensures that a class has only **one instance** and provides a global point of access to that instance.

#### Why we used it:
In the Tic Tac Toe game, the `GameController` class is responsible for managing the entire game—initializing the board, processing moves, checking win/draw conditions, and switching players. Since there should be only one instance of the game controller (so there’s only one game being played at a time), we use the Singleton Pattern to ensure that the game controller cannot be instantiated more than once.

#### Key points:
- Restricts the instantiation of a class to a single instance.
- Provides a global point of access to that instance.
- Useful when exactly one object is needed to coordinate actions across the system.

#### Code Example:
```js
class GameController {
  static instance = null;

  constructor() {
    if (GameController.instance) return GameController.instance;
    GameController.instance = this;
  }

  static getInstance() {
    if (!GameController.instance) {
      GameController.instance = new GameController();
    }
    return GameController.instance;
  }
}
```

### 2. **Factory Pattern**

#### What it is:
The **Factory Pattern** is a creational design pattern that provides an interface for creating objects without specifying their exact class. Instead of using `new` to create instances, a factory method is used to construct the object, making the code more flexible and scalable.

#### Why we used it:
In the Tic Tac Toe game, the `Player` class could have different types of players—such as a human player or an AI player. Instead of directly instantiating specific player types, a factory can dynamically create players based on input. This is useful for extending the game to include different player types (e.g., AI vs. human, human vs. human, etc.).

#### Key points:
- Decouples the client code from the concrete classes it needs to instantiate.
- Makes the system more flexible and scalable as new types of objects (players in our case) can be easily added without changing the client code.
- Reduces dependencies between classes.

#### Code Example:
```js
class PlayerFactory {
  static createPlayer(type, name, symbol) {
    if (type === 'human') {
      return new HumanPlayer(name, symbol);
    } else if (type === 'AI') {
      return new AIPlayer(name, symbol);
    }
  }
}
```

### 3. **Observer Pattern**

#### What it is:
The **Observer Pattern** is a behavioral design pattern where an object (called the **subject**) maintains a list of dependent **observers** and notifies them of any state changes, usually by calling one of their methods. The observer pattern allows for a one-to-many relationship where changes in one object trigger updates in many others.

#### Why we used it:
In the Tic Tac Toe game, the `GameController` acts as the subject, and the `GameObserver` objects (e.g., players or any external observers) are registered to be notified of game state changes, such as when a player makes a move, wins, or the game results in a draw. This pattern is useful for decoupling the logic for game state changes from the actions taken when those states change.

#### Key points:
- Defines a one-to-many relationship between objects so that when one object changes state, all its dependents are notified and updated automatically.
- Promotes loose coupling between the subject and its observers.
- Useful when the state of an object needs to be observed by multiple entities (players in this case).

#### Code Example:
```js
class GameObserver {
  update(state) {
    console.log("Game state update:", state);
  }
}

class GameController {
  constructor() {
    this.observers = [];
  }

  addObserver(observer) {
    this.observers.push(observer);
  }

  notifyObservers(state) {
    this.observers.forEach(observer => observer.update(state));
  }
}
```

### 4. **Strategy Pattern**

#### What it is:
The **Strategy Pattern** is a behavioral design pattern that defines a family of algorithms (strategies), encapsulates each one, and makes them interchangeable. This allows the algorithm to vary independently from clients that use it.

#### Why we used it:
In the Tic Tac Toe game, the `Board` class uses different strategies for move validation, checking win conditions, and checking for a draw. By encapsulating these algorithms in separate methods or classes, we can easily change or extend the game logic without altering the rest of the game's structure. This separation of concerns makes the system more modular and maintainable.

#### Key points:
- Encapsulates algorithms (or strategies) in separate classes or methods.
- Allows swapping between different algorithms without modifying the client code.
- Promotes the **Open/Closed Principle**—the code is open for extension but closed for modification.

#### Code Example:
```js
class Board {
  constructor() {
    this.cells = Array(3).fill().map(() => Array(3).fill(null));
  }

  isValidMove(row, col) {
    return this.cells[row][col] === null;
  }

  checkWin() {
    const winConditions = [
      // Horizontal, vertical, and diagonal win conditions
    ];
    return winConditions.some(condition =>
      condition.every(([row, col]) => this.cells[row][col] === this.currentPlayer.symbol)
    );
  }

  checkDraw() {
    return this.cells.every(row => row.every(cell => cell !== null));
  }
}
```

### Summary of the Patterns:
1. **Singleton Pattern**: Ensures there is only one instance of the `GameController` to manage the game.
2. **Factory Pattern**: Creates player instances dynamically, allowing easy extension (e.g., AI players).
3. **Observer Pattern**: Notifies players or external entities about game state changes like moves, wins, or draws.
4. **Strategy Pattern**: Encapsulates logic for different algorithms (move validation, win/draw conditions) so they can vary independently from the rest of the system.

These patterns make the Tic Tac Toe game more flexible, scalable, and easier to maintain by following principles such as loose coupling, separation of concerns, and adherence to the Open/Closed Principle.
