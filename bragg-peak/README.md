# Proton Bragg Peak Analysis
Protons of energy 100 MeV are shot from (0,0,-12.5 cm) along z axis on  water box of size 1 cm x 1 cm x 25 cm. The dose deposition is histogrammed using a scoring volume.

### Activities  

- You can run the programme in two ways:  
    - a. With visualization: `./exampleB1`
    - b. Without visualization: `./exampleB1 bragg_peak.mac`

The second option will generate a scoring volume file called eDep.txt which you can use to analyse the data. You can change the particles and energy in the `bragg_peak.mac` file.

- Change the particle energy from 50 Mev to 150 MeV in 20 MeV steps and plot the energy deposition as a function of distance for each of the energies

- Make a plot of the range as a function of energy

- Replace the particle by pi- or pi+ or gamma and repeat the exercise. Observe, qualitatively, what happens to the shape of the curve.
