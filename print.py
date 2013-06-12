#!/usr/bin/env python
# encoding: utf-8
"""
print.py

Walk over directory to print figures in all format
"""
import os, sys, json, pprint

def my_walk():
    for root, dirs, files in os.walk('.'):
        if root.find('.git') >0:
            if dirs:
                dirs[:] = []  # skip .git
        if 'plot.C' in files:
            yield root, dirs, files

def copy_fig(fig_dir, root):
    to_dir = fig_dir + '/' + root
    try:
        os.makedirs(to_dir)
    except OSError:
        pass
    os.system('cp -f *.eps ' + to_dir)
    os.system('cp -f *.pdf ' + to_dir)
    os.system('cp -f *.png ' + to_dir)

def run(fig_dir, plot='all'):
    index = {}
    for root, dirs, files in my_walk():
        if not plot == 'none' and (plot == 'all' or (root+'/').find(plot) > 0):
            current_dir = os.getcwd()
            os.chdir(root)
            cmd = 'root -b -q plot.C'
            os.system(cmd)
            copy_fig(fig_dir, root)
            os.chdir(current_dir)
        tmp, section, figname = root.split('/')
        index.setdefault(section, [])
        index[section].append(figname)
        # print section, figname
    f = open(fig_dir + '/index.json', 'w')
    f.write(json.dumps(index))
    f.close()
    pprint.pprint(index)

if __name__ == '__main__':
    try:
        plot = sys.argv[1]
    except IndexError:
        plot = 'all'
    try:
        fig_dir = sys.argv[2]
    except IndexError:
        fig_dir = '.'

    run(os.path.abspath(fig_dir+'/figures'), plot=plot)
    # run(os.path.abspath(fig_dir+'/figures'), draw=False)
