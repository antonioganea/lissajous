# Lissajous
  Interactive Lissajous Curve Plotter

# Idea
  This software draws 2 oscillating points on perpendicular trajectories. The resulting point ( of coordinates x, y ) traces a specific image called a lissajous curve.
  The shape of a lissajous curve depends on the input parameters : omegaX, omegaY, amplitudeX, amplitudeY, phiX, phiY.

  The points are plotted with this formula :
  ```
  for ( float t = 0; t < PI * 2.f; t+= 0.001f ){
    x = amplitudeX * sin ( omegaX * t + phiX );
    y = amplitudeY * sin ( omegaY * t + phiY );
  }
  ```
  Note : for simplicity amplitudeX = amplitudeY = amplitude



# Controls
  A & S modify omegaX
  Z & X modify omegaY
  Q & W modify amplitude
  C & V modify phiX
  D & F modify phiY
  R toggles on phi animation mode
  T resets phiX, phiY to 0
  Y toggles circle animation

## Downloadable .exe
  [Download link](https://www.dropbox.com/s/kcsm74m9q37oun0/Lissajous.7z?dl=0)

# Dependencies
  [SFML](https://www.sfml-dev.org)
