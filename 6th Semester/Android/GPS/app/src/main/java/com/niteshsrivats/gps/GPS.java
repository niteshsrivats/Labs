package com.niteshsrivats.gps;

import android.Manifest;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import android.os.IBinder;

public class GPS extends Service implements LocationListener {

    private final Context mContext;
    private final boolean isGPSEnabled, isNetworkEnabled;
    private final long MinDistanceChangeForUpdates = 10;
    private final long MinTimeBetweenUpdates = 1000 * 60;
    private final LocationManager locationManager;

    public GPS(Context context) {
        this.mContext = context;
        locationManager = (LocationManager) mContext.getSystemService(LOCATION_SERVICE);

        if (locationManager == null) {
            isGPSEnabled = false;
            isNetworkEnabled = false;
        } else {
            isGPSEnabled = locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER);
            isNetworkEnabled = locationManager.isProviderEnabled(LocationManager.NETWORK_PROVIDER);
        }
    }

    public Location getLocation() {
        Location gpsLocation = getGpsLocation();
        if (gpsLocation == null) {
            return getNetworkLocation();
        }
        return gpsLocation;
    }

    private Location getGpsLocation() {
        if (isGPSEnabled && mContext.checkSelfPermission(Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, MinTimeBetweenUpdates, MinDistanceChangeForUpdates, this);
            return locationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
        }
        return null;
    }

    private Location getNetworkLocation() {
        if (isNetworkEnabled && mContext.checkSelfPermission(Manifest.permission.ACCESS_COARSE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
            locationManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, MinTimeBetweenUpdates, MinDistanceChangeForUpdates, this);
            return locationManager.getLastKnownLocation(LocationManager.NETWORK_PROVIDER);
        }
        return null;
    }

    @Override
    public void onLocationChanged(Location location) {

    }

    @Override
    public void onProviderDisabled(String provider) {

    }

    @Override
    public void onProviderEnabled(String provider) {

    }

    @Override
    public void onStatusChanged(String provider, int status, Bundle extras) {

    }

    @Override
    public IBinder onBind(Intent arg0) {
        return null;
    }
}
