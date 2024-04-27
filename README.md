# Exercises for NEUS 2024 (ICTS, Bengaluru)

## To run the codes:

- Open VSCode and from the menu, open a new terminal 

- On the terminal, issue the following commands
    - `git clone https://github.com/deepaksamuel/neus-exercises.git`

This command will download all the files required for the exercises

- For the compilation to succeed, you must set the G4 envionment variables. This is typically done by sourcing a script, in the terminal where you compile the code.

    - For snap installations: `source /snap/gate/45/usr/local/bin/geant4.sh`
    - If compiled from source: YOUR_G4_INSTALL_FOLDER/install/bin/geant4.sh

- For compiling the alpha-scattering code:
    - `cd alpha-scattering`
    - `mkdir build`
    - `cmake ../`
    - `make`
    - `./exampleB1`

- Note: 
    - everytime you open a new terminal the `geant4.sh` file should be sourced
    - everytime you make a change to your code, only the last two commands should be used:
        - `make`
        - `./exampleB1`
