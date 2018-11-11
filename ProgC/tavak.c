float const tavak[] = {
    106.6, 52.8, 107.6, 53.5, 108.4, 54.3, 109.1, 55.0, 109.9, 55.7, 109.7, 54.7, 109.2, 53.6, 
    108.2, 52.8, 106.6, 52.3, 105.7, 51.8, 104.3, 51.5, 105.5, 52.3, 106.6, 52.8, 0, 0, -99.0, 
    53.9, -98.0, 54.3, -96.4, 51.4, -96.7, 50.4, -97.2, 51.5, -98.2, 52.2, -99.2, 53.2, -99.0, 
    53.9, 0, 0, -115.0, 62.0, -116.1, 62.8, -114.5, 62.4, -113.4, 62.0, -111.8, 62.4, -110.2, 
    63.1, -109.1, 62.8, -110.1, 62.5, -111.3, 62.3, -112.6, 61.6, -113.6, 61.1, -115.3, 60.9, 
    -116.4, 60.9, -118.1, 61.3, -116.8, 61.3, -115.7, 61.7, -115.0, 62.0, 0, 0, -79.1, 43.3, -77.6,
    44.0, -76.6, 44.2, -76.9, 43.3, -78.5, 43.4, -79.1, 43.3, 0, 0, -83.1, 42.1, -81.8, 42.3, 
    -80.5, 42.6, -78.9, 43.0, -79.8, 42.3, -81.0, 41.8, -82.3, 41.4, -83.5, 41.7, -83.1, 42.1, 0, 
    0, -89.6, 48.0, -88.6, 48.6, -87.2, 48.7, -86.0, 48.0, -84.9, 47.9, -84.4, 46.8, -86.1, 46.7,
    -87.7, 46.8, -88.8, 47.2, -90.4, 46.6, -92.0, 46.7, -90.6, 47.7, -89.6, 48.0, 0, 0, 33.9, 
    0.1, 34.1, -1.1, 33.3, -2.0, 32.4, -2.5, 31.8, -1.6, 32.3, -0.1, 33.3, 0.3, 33.9, 0.1, 0, 0, 
    29.8, 61.2, 30.9, 61.8, 32.5, 61.1, 31.7, 60.2, 30.5, 60.6, 29.8, 61.2, 0, 0, 79.0, 46.7, 
    77.2, 46.4, 75.6, 46.5, 74.3, 46.0, 74.1, 45.0, 73.4, 45.8, 74.9, 46.8, 76.2, 46.8, 77.9, 
    46.6, 79.0, 46.7, 0, 0, 30.8, -8.6, 30.1, -7.3, 29.2, -6.0, 29.3, -3.5, 29.7, -4.4, 29.8, 
    -5.5, 30.5, -6.9, 31.2, -8.7, 30.8, -8.6, 0, 0, 35.3, -14.3, 34.3, -13.4, 34.0, -12.2, 34.3, 
    -10.4, 34.9, -11.5, 34.9, -13.7, 35.3, -14.3, 0, 0, 60.1, 44.3, 59.3, 45.0, 58.5, 44.2, 58.7, 
    45.5, 59.6, 46.3, 60.2, 44.8, 60.1, 44.3, 0, 0, 14.0, 59.2, 12.8, 58.5, 13.6, 59.3, 14.0, 
    59.2, 0, 0, -80.7, 26.8, -80.7, 26.8, 0, 0, -84.9, 11.1, -85.8, 11.5, -84.9, 11.1, -84.9, 
    11.1, 0, 0, 37.1, 11.9, 37.1, 11.9, 0, 0, -69.4, -16.1, -69.4, -16.1, 0, 0, -99.4, 53.1, 
    -100.4, 53.3, -100.0, 54.2, -99.4, 53.3, -99.4, 53.1, 0, 0, 35.7, 62.3, 36.4, 61.3, 35.4, 60.9,
    34.5, 61.9, 35.5, 62.3, 35.7, 62.3, 0, 0, -112.2, 41.3, -112.2, 41.3, 0, 0, -117.8, 66.2, 
    -119.7, 65.7, -121.4, 64.9, -122.6, 65.0, -125.0, 66.0, -119.5, 67.0, -117.6, 66.6, -117.8, 
    66.2, 0, 0, -109.7, 59.0, -111.1, 58.6, -109.1, 59.6, -106.5, 59.3, -109.7, 59.0, -109.7, 
    59.0, 0, 0, -101.9, 58.0, -103.2, 56.3, -102.8, 57.3, -102.1, 58.0, -101.9, 58.0, 0, 0, -80.4,
    45.6, -79.8, 44.8, -80.9, 44.6, -81.8, 44.1, -82.4, 43.0, -82.7, 44.0, -83.7, 43.6, -83.3, 
    44.7, -84.1, 45.6, -83.2, 46.2, -81.6, 46.1, -80.4, 45.6, 0, 0, -85.5, 46.0, -85.5, 44.8, 
    -86.5, 44.1, -86.2, 43.0, -86.6, 41.9, -87.8, 42.2, -87.9, 43.2, -87.5, 44.5, -87.0, 45.7, 
    -85.5, 46.0, 0, 0, 49.1, 41.3, 47.5, 43.0, 46.7, 44.6, 47.7, 45.6, 49.1, 46.4, 51.2, 47.0, 
    53.0, 46.9, 53.0, 45.3, 51.3, 45.2, 50.3, 44.6, 51.3, 43.1, 52.5, 42.8, 52.5, 41.8, 53.7, 
    42.1, 54.7, 41.0, 52.9, 40.9, 53.4, 40.0, 53.9, 39.0, 53.7, 37.9, 52.3, 36.7, 50.8, 36.9, 
    49.2, 37.6, 48.9, 38.8, 49.6, 40.2, 49.1, 41.3, 0, 0, -1, -1
};