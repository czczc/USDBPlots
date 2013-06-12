#!/usr/bin/env python
# encoding: utf-8
"""
print.py

Walk over directory to print figures in all format
"""
import os, sys, json

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

def run(fig_dir, draw=True):
    index = {}
    for root, dirs, files in my_walk():
        if draw:
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

if __name__ == '__main__':
    try:
        fig_dir = sys.argv[1]
    except IndexError:
        fig_dir = '.'

    # run(os.path.abspath(fig_dir+'/figures'), draw=True)
    run(os.path.abspath(fig_dir+'/figures'), draw=False)
