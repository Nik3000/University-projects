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
        pad_w, pad_h = int(0.2*w), int(0.05*h) #настройка коэффициентов прямоугольников
        cv2.rectangle(img, (x+pad_w, y+pad_h), (x+w-pad_w, y+h-pad_h), (0, 255, 0), thickness)


if __name__ == '__main__':
    import sys
    from glob import glob
    import itertools as it
    
    video = cv2.VideoCapture('in960x540.mp4')
    #video = cv2.VideoCapture('Test.mp4')
    #video = cv2.VideoCapture(0)
    hog = cv2.HOGDescriptor()
    hog.setSVMDetector( cv2.HOGDescriptor_getDefaultPeopleDetector() )

    fps = 0
    start = time.time()
    while True:
        flag, img = video.read()
        fps = fps + 1
        if flag:    
            found, w = hog.detectMultiScale(img, winStride=(8,8), padding=(64,64), scale=1.06)
            found_filtered = []
            for ri, r in enumerate(found):
                for qi, q in enumerate(found):
                    if ri != qi and inside(r, q):
                        break
                else:
                    found_filtered.append(r)
        if flag:
            draw_detections(img, found)
            draw_detections(img, found_filtered, 2)
        
        end = time.time()
        if (end - start) > 1:
            start = time.time()
            print(fps, 'fps', '%d (%d) found' % (len(found_filtered), len(found)))
            fps = 0
            
        cv2.imshow('img', img)
        ch = cv2.waitKey(1) & 0xff
        if ch == 27: break

cv2.destroyAllWindows()
