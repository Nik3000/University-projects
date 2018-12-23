import cv2
import sys
import numpy as np
import time
import numba
 
if __name__ == '__main__' :
 
    # Set up tracker.
    # Instead of MIL, you can also use
    # BOOSTING, KCF, TLD, MEDIANFLOW or GOTURN
     
    tracker = cv2.TrackerMIL_create()
    tracker2 = cv2.TrackerMIL_create()
 
    # Read video
    #video = cv2.VideoCapture(0)
    #video = cv2.VideoCapture('2in960x540.mp4')
    video = cv2.VideoCapture('second_in640x480.mp4')

    #Exit if video not opened.
    if not video.isOpened():
        print ("Could not open video")
        sys.exit()
 
    #Read first frame.
    ok, frame = video.read()
    if not ok:
        print ("Cannot read video file")
        #ys.exit()
     
    # Define an initial bounding box
    bbox = (287, 23, 86, 320) 
    # Uncomment the line below to select a different bounding box
    bbox = cv2.selectROI(frame, False) 
    # Initialize tracker with first frame and bounding box
    ok = tracker.init(frame, bbox)

    #Read first frame.
    ok, frame1 = video.read()
    if not ok:
        print ("Cannot read video file")
        #ys.exit()

    bbox2 = (287, 23, 86, 320)
    bbox2 = cv2.selectROI(frame1, False)
    ok2 = tracker2.init(frame1, bbox2)

    v = 0
    fps = 0
    start = time.time()
    while True:
        # Read a new frame
        ok, frame = video.read()
        ok2, frame1 = video.read()
        fps = fps + 1
        v = v + 1
        if not ok:
            break
         
        # Update tracker
        ok, bbox = tracker.update(frame)
        ok2, bbox2 = tracker2.update(frame1)
        # Draw bounding box
        if ok:
            p1 = (int(bbox[0]), int(bbox[1]))
            p2 = (int(bbox[0] + bbox[2]), int(bbox[1] + bbox[3]))
            cv2.rectangle(frame, p1, p2, (0,0,255))

        if ok2:
            p11 = (int(bbox2[0]), int(bbox2[1]))
            p22 = (int(bbox2[0] + bbox2[2]), int(bbox2[1] + bbox2[3]))
            cv2.rectangle(frame, p11, p22, (0,0,255))
        
        end = time.time()
        if (end - start) > 1:
            start = time.time()
            print(fps, '   ', v)
            fps = 0
        # Display result
        cv2.imshow("Tracking", frame)
 
        # Exit if ESC pressed
        k = cv2.waitKey(1) & 0xff
        if k == 27 : break
cv2 . destroyAllWindows ()
