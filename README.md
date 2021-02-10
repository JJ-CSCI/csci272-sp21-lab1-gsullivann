# Lab 1

## Task: Computation modeling in biology

Write a program that simulates the growth of **parasite population in an animal** over time. Each parasite organism **reproduces itself** at **some time interval**. Animals may **undergo drug treatment** to inhibit the reproduction process, and clear the parasites from their body. However, some of the parasite are **resistant to drugs** and **may survive**.

### Details

- Identify objects that simulation uses from the above description
- Identify objects' properties and responsibilities
- Define C++ class for every object listing all possible members (data and functional)
    - All data members must have **private** access
    - Provide for each private data member a public method that allows access its value
        - Naming convention: You can name your data member as you wish, however any methods that provide access to the field have to be named as follows: *get<FieldName\>*
        - E.g. Private field *speed* should have a public access method called *getSpeed()*.
- Bonus points
    - use proper coding style (see below)

## Steps

### Parasite Class
- Create **Parasite** class declaration in [main.cpp](main.cpp) file
- Include into the class definition all parasite properties
    - a reproduction rate as `double` type field `reproductionRate`
    - a drug resistance as `double` type field `resistance`
- Provide to encapsulated fields access functional members: `getReproductionRate` and `getResistance`
- Add functional members corresponding to parasite responsibilities
    - For *reproducibility*, add method `reproduce` that, when is called, increases the reproduction rate by 10%
    - For *survival*, add method `survive` that, when is called, increases the parasite resistance by 5%
    - Both above methods have no parameters and do not return any value

### Animal Class

- Write a **Animal** class declaration in [main.cpp](main.cpp) file
- Similarly to **Parasite** class, include into the class definition all animal properties
    - an immunity rate as `double` type field `immunity`
    - a number of parasites in the animal as `unsigned int` type field `parasites`
      - Use the initialized list to set the values of this field to `1000`
- Provide to encapsulated fields access functional members: `getImmunity` and `getParasiteNumber`
- Add functional members corresponding to parasite responsibilities
    - For *taking drug*, add method `takeDrug` that returns nothing, and, when is called, increases the immunity of the animal by 7% and reduces the parasite population by `100`

## Test

Press **Run** button to execute and test your program.

- Or run `make test` command in the command line to verify the correctness of your program.

## Submission

- Commit & push all changes that to the corresponding assignment repository on GitHub, using the **Repl.it** interface - **Version control** tab.
  - Make sure that you committed changes of the following files:
    - `main.cpp`
- Submit the link of the assignment GitHub repository in the corresponding assignment submission the Blackboard.

### Before You Submit

You are required to test that your submission works properly before submission. Make sure that your program compiles without errors. Once you have verified that the submission is correct, you can submit your work.

### Coding Style

In any programming project, matching the existing coding style is important. Having different coding styles intermixed leads to confusion and bugs. Students are required to follow the particular existing coding style that maintains the indentation style in `.cpp` and `.h` files using spaces, not tabs.

In particular, pay close attention to function declarations and how the function name begins the line after the function return type. For helper functions which are limited in scope to a specific file, you must declare the function as `static` in the same file in which it is used.

*Indentation*: The indentation style for your work have to be 4 spaces. Many students are taught to use tabs for indentation, which can make code very hard to read, especially when there are several levels of indentation.

For additional information of C++ coding style see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
