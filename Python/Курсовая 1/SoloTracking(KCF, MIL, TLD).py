import cv2
import sys
import numpy as np
import time
 
if __name__ == '__main__' :
 
    # Set up tracker.
    # Instead of MIL, you can also use
    # BOOSTING, KCF, TLD, MEDIANFLOW or GOTURN
     
    tracker = cv2.TrackerMIL_create()
 
    # Read video
    video = cv2.VideoCapture(0)


    
    #tracker = cv2.Tracker_create("KCF")
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

    #v = 0
    fps = 0
    start = time.time()
    while True:
        # Read a new frame
        ok, frame = video.read()
        fps = fps + 1
        if not ok:
            break
         
        # Update tracker
        ok, bbox = tracker.update(frame)
 
        # Draw bounding box
        if ok:
            p1 = (int(bbox[0]), int(bbox[1]))
            p2 = (int(bbox[0] + bbox[2]), int(bbox[1] + bbox[3]))
            cv2.rectangle(frame, p1, p2, (0,0,255))

        end = time.time()
        if (end - start) > 1:
            start = time.time()
            print(fps)
            fps = 0
        # Display result
        cv2.imshow("Tracking", frame)
 
        # Exit if ESC pressed
        k = cv2.waitKey(1) & 0xff
        if k == 27 : break
