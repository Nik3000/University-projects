from __future__ import print_function

import numpy as np
import cv2
import time

def inside(r, q):
    rx, ry, rw, rh = r
    qx, qy, qw, qh = q
    return rx > qx and ry > qy and rx + rw < qx + qw and ry + rh < qy + qh

def draw_detections(img, rects, thickness = 1):
    for x, y, w, h in rects:
        #pad_w, pad_h = int(0.15*w), int(0.05*h)
        pad_w, pad_h = int(0.15*w), int(0.05*h) #настройка коэффициентов прямоугольников
        cv2.rectangle(img, (x+pad_w, y+pad_h), (x+w-pad_w, y+h-pad_h), (0, 255, 0), thickness)


if __name__ == '__main__':
    import sys
    from glob import glob
    import itertools as it
    
    hog = cv2.HOGDescriptor()
    hog.setSVMDetector( cv2.HOGDescriptor_getDefaultPeopleDetector() )

    start = time.time()
    img = cv2.imread('Test6m.jpg')

        
    found, w = hog.detectMultiScale(img, winStride=(4,4), padding=(32,32), scale=1.06)
    found_filtered = []
    for ri, r in enumerate(found):
        for qi, q in enumerate(found):
            if ri != qi and inside(r, q):
                break
        else:
            found_filtered.append(r)
        
    draw_detections(img, found)
    draw_detections(img, found_filtered, 2)
        
    end = time.time()
    print('Время работы - ', end - start)

    fw = 900
    rr = float(fw) / img.shape[1]
    dim = (fw, int(img.shape[0]*rr))
    resized = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)

    cv2.imshow('img', resized)
    ch = cv2.waitKey(1) & 0xff
    if ch == 27: 
        cv2.destroyAllWindows()
