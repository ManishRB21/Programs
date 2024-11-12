### Resources

## JS questions

https://www.geeksforgeeks.org/validate-a-password-using-html-and-javascript/?ref=ml_lbp

https://www.geeksforgeeks.org/create-a-pagination-using-html-css-and-javascript/

https://www.geeksforgeeks.org/how-to-build-password-generator-using-node-js/?ref=ml_lbp

https://www.fullstack.cafe/blog/node-js-interview-questions

https://www.youtube.com/watch?v=kCfTEoeQvQw (debounce throttle)

https://www.geeksforgeeks.org/create-an-infinite-scroll-page-using-html-css-javascript/?ref=ml_lbp

https://www.geeksforgeeks.org/show-hide-password-using-javascript/


## videos

https://www.youtube.com/watch?v=BwyFLRVYbvU (HOF)

webpack nodejs

https://www.youtube.com/watch?v=uhtmTe26rqo

https://www.youtube.com/watch?v=TDe7DRYK8vU (auth sesh and cookies)

https://www.youtube.com/watch?v=1r-F3FIONl8&t=352s (stripe)

https://www.youtube.com/watch?v=U6YH8WrQJJQ (pagination)

https://www.youtube.com/watch?v=DQP53RgTWMA (image gallery)

https://www.youtube.com/watch?v=Wv0kMtWDT_Q (design patterns)

https://www.youtube.com/watch?v=_NFdUC2W0W4 (draggable elements)

https://www.youtube.com/watch?v=zTjRZNkhiEU (git)

https://www.youtube.com/watch?v=XQWO5Dh88h8 (github actions)




## Interview

https://www.ambitionbox.com/interviews/nutanix-question/split-the-string-you-are-given-a-string-str-of-n-lowercase-alphabets-your-task-is-to-check-whether-it-is-possible-to-split-the-given-string-into-three-non-empty-substrings-juKA0Hu9

https://www.geeksforgeeks.org/check-if-a-string-can-be-split-into-3-substrings-such-that-one-of-them-is-a-substring-of-the-other-two/

https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

---

# JavaScript Design Patterns

## Table of Contents
1. [Creational Patterns](#creational-patterns)
   - [Singleton](#singleton)
   - [Factory](#factory)
   - [Builder](#builder)
2. [Structural Patterns](#structural-patterns)
   - [Adapter](#adapter)
   - [Decorator](#decorator)
3. [Behavioral Patterns](#behavioral-patterns)
   - [Observer](#observer)
   - [Strategy](#strategy)

---

## Creational Patterns

### Singleton

- **Definition**: The Singleton Pattern ensures a class has only one instance and provides a global point of access to it.
- **Problem**: Useful for managing shared resources like a database or logging service where multiple instances could cause conflicts.
- **Use Case**: Database connection managers, configurations, or logging systems.
  
#### Code Example

```javascript
class Logger {
  constructor() {
    if (Logger.instance) {
      return Logger.instance;
    }
    Logger.instance = this;
    this.logs = [];
  }

  addLog(message) {
    this.logs.push(message);
    console.log(`Log added: ${message}`);
  }

  getLogCount() {
    return this.logs.length;
  }
}

// Usage
const logger1 = new Logger();
const logger2 = new Logger();

logger1.addLog("App started.");
console.log(logger1.getLogCount()); // 1

logger2.addLog("User logged in.");
console.log(logger2.getLogCount()); // 2

console.log(logger1 === logger2); // true, both instances are the same
```

---

### Factory

- **Definition**: The Factory Pattern provides a way to create objects without specifying the exact class of the object that will be created.
- **Problem**: Avoids tightly coupling code with specific classes, making it easier to switch or add new object types.
- **Use Case**: When you need to create different types of objects based on input, such as various user types (Admin, Guest, Member) in an application.

#### Code Example

```javascript
class User {
  constructor(role) {
    this.role = role;
  }
}

class Admin extends User {
  constructor() {
    super("Admin");
  }
}

class Guest extends User {
  constructor() {
    super("Guest");
  }
}

class UserFactory {
  static createUser(role) {
    switch (role) {
      case "Admin":
        return new Admin();
      case "Guest":
        return new Guest();
      default:
        throw new Error("Invalid role type.");
    }
  }
}

// Usage
const adminUser = UserFactory.createUser("Admin");
console.log(adminUser.role); // "Admin"

const guestUser = UserFactory.createUser("Guest");
console.log(guestUser.role); // "Guest"
```

---

## Structural Patterns

### Adapter

- **Definition**: The Adapter Pattern allows incompatible interfaces to work together.
- **Problem**: Sometimes classes have incompatible interfaces, and an adapter can bridge these gaps.
- **Use Case**: When working with a legacy system where a new interface or API needs to be integrated without modifying the existing code.

#### Code Example

```javascript
class OldSystem {
  oldRequest() {
    return "Old system response";
  }
}

class NewSystem {
  newRequest() {
    return "New system response";
  }
}

class Adapter {
  constructor() {
    this.newSystem = new NewSystem();
  }

  request() {
    // Adapting the old request to use the new request
    return this.newSystem.newRequest();
  }
}

// Usage
const adapter = new Adapter();
console.log(adapter.request()); // "New system response"
```

---

## Behavioral Patterns

### Observer

- **Definition**: The Observer Pattern allows an object (subject) to maintain a list of dependents (observers) and notify them of state changes.
- **Problem**: Useful for implementing a one-to-many dependency so that when one object changes state, all its dependents are notified.
- **Use Case**: Commonly used in event handling, such as chat applications where users subscribe to notifications.

#### Code Example

```javascript
class Subject {
  constructor() {
    this.observers = [];
  }

  subscribe(observer) {
    this.observers.push(observer);
  }

  unsubscribe(observer) {
    this.observers = this.observers.filter(obs => obs !== observer);
  }

  notify(data) {
    this.observers.forEach(observer => observer.update(data));
  }
}

class Observer {
  update(data) {
    console.log("Observer received data:", data);
  }
}

// Usage
const subject = new Subject();
const observer1 = new Observer();
const observer2 = new Observer();

subject.subscribe(observer1);
subject.subscribe(observer2);

subject.notify("New update available!"); // All subscribed observers will be notified
```

---

### Strategy

- **Definition**: The Strategy Pattern allows you to define a family of algorithms, encapsulate each one, and make them interchangeable.
- **Problem**: This pattern is useful when you have multiple ways of doing something, and you want to choose the algorithm at runtime.
- **Use Case**: Sorting data in different ways, validating user input based on different rules.

#### Code Example

```javascript
class Context {
  constructor(strategy) {
    this.strategy = strategy;
  }

  executeStrategy(data) {
    return this.strategy.doAlgorithm(data);
  }
}

class StrategyA {
  doAlgorithm(data) {
    return data.sort((a, b) => a - b);
  }
}

class StrategyB {
  doAlgorithm(data) {
    return data.sort((a, b) => b - a);
  }
}

// Usage
const data = [3, 1, 2];
const context = new Context(new StrategyA());

console.log(context.executeStrategy(data)); // Sorted in ascending order: [1, 2, 3]

context.strategy = new StrategyB();
console.log(context.executeStrategy(data)); // Sorted in descending order: [3, 2, 1]
```

---
