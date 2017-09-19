from mpl_toolkits.axes_grid.axislines import SubplotZero
from matplotlib.ticker import MultipleLocator, FuncFormatter
import matplotlib.pyplot as plt
import numpy as np
import importlib
importlib.import_module('mpl_toolkits.axes_grid.axislines')

plt.ion()

fig = plt.figure(1)
ax = SubplotZero(fig, 111)
fig.add_subplot(ax)

for dir in ax.axis:
    ax.axis[dir].set_visible(dir.endswith("zero"))

ax.set_aspect('equal')

tick_format = lambda x, i: '' if x == 0.0 else '%.1f' % x
for a in [ax.xaxis, ax.yaxis]:
    a.set_minor_locator(MultipleLocator(0.02))
    a.set_major_formatter(FuncFormatter(tick_format))

theta = np.arange(2*np.pi/3,6*np.pi,0.01)

ax.plot(np.cos(theta)*(1+np.sin(theta)),-np.sin(theta)*(1+np.sin(theta)) , lw=1)

plt.show()
input()
