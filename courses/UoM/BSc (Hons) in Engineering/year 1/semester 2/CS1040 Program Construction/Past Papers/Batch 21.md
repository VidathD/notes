# Batch 21 (2023)

## Question 1

### Part C

1. During compile time, no physical memory is used. However, the compiler does type checking and note that `int i` will require 4 bytes are `Integer intObj` will require a 4 byte reference. This information is stored in the bytecode.
2. During runtime, setting `i=123` will store the value directly in the stack using 4 bytes. `intObj=new Integer(123)` will use 4 bytes in the stack to store the reference to the location in heap memory where 16 bytes will be used to store the value as an integer object.

## Question 2

### Part A

1. Overloading
2. Overriding

### Part B

Create an abstract class called `menuItem` that contains state variables for `price` and `itemID`. It should also include the constructor and common methods `getItemId`, `getPrice`, `setPrice` and an abstract method `serve`. Create an abstract class `foodItem` that inherits from `menuItem` and adds the state variable `shelfLife` and the method `getShelfLife`. Create an interface `caramalisable` that requires the `addCaramel` method. Create concrete class `Coffee` by extending `menuItem` and implementing `caramalisable`. Create `Doughtnut` by extending `foodItem` and implementing `caramalisable`. Create `Sandwitch` by extending `foodItem`. 

### Part C

Polymorphism establishes an “is a” relationship and allows a parent to represent the many forms of its children. Here, if we store the ordered objects in a `List<menuItem>` and iterate over it and call the `.serve()` method on each object, dynamic binding enabled by polymorphism will ensure that `Coffee` outputs `"I am served in a cup!"` while `Doughnut` and `Sandwich` will output `"I am served on a plate!"`, which shows that the parent `menuItem` class is representing all of its children classes and selecting the suitable method depending on the current child.

### Part D

The state variables are set to public. However, since there are getters and setters defined, we can use the concept of encapsulation and set those variables to private. Then the state variables can be only accessed and changed using the designated getters and setters which enforce validation and data integrity.

### Part E

```java
abstract class menuItem{  
    private double price;  
    private int itemID;  
  
    public menuItem(double price, int itemID){  
        this.price=price;  
        this.itemID=itemID;  
    }  
  
    public void setPrice(double price){  
        this.price=price;  
    }  
  
    public int getItemID(){  
        return this.itemID;  
    }  
  
    // The original code doesn't have a getPrice method, but it seems pretty important so I added it  
    public double getPrice(){  
        return this.price;  
    }  
  
    public abstract String serve();  
}  
  
abstract class foodItem extends menuItem{  
    private int shelfLife;  
  
    public foodItem(double price, int itemID, int shelfLife){  
        super(price,itemID);  
        this.shelfLife=shelfLife;  
    }  
  
    public int getShelfLife(){  
        return this.shelfLife;  
    }  
  
    public String serve(){  
        return "I am served on a plate!";  
    }  
}
```