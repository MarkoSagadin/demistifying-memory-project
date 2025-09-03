# Demistifying memory repository

This repository was created for demonstration purposes as a part of my talk
"Demystifying Memory: A Practical Tutorial on Managing & Optimizing Memory in
Zephyr" that I held at Zephyr developer summit at Open Source Summit Europe 2025
in Amsterdam, Netherlands.

Slides to the talk can be found on the
[Sched event page](https://osseu2025.sched.com/event/25Vvc/demystifying-memory-a-practical-tutorial-on-managing-optimizing-memory-in-zephyr-marko-sagadin-irnas),
as well as in this repository, in the `doc/` folder.

## Getting started

Before getting started, make sure you have a proper nRF Connect SDK development
environment. Follow the official
[Installation guide](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/nrf/installation/install_ncs.html).

## Repo setup

To initialize the repository and update the modules, run the following commands:

```shell
west init -m https://github.com/MarkoSagadin/demistifying-memory-project demistifying-memory-project
cd demistifying-memory-project/demistifying-memory-project.git
west update
```

## Configuring Azure IoT Hub app

For the app to work as intended you willl need to configure several tings.

### Azure IoT Hub instance

You will need:

- An Azure IoT Hub instance to connect to.
- A Device Provisioning Service (DPS) instance to provision the device.
  (Generally this is not a mandatory component, but it is used in this project).
- A set of certificates, placed in the `app/certs/` folder.

Kconfigs that you will need to manually set in `app/prj.conf`:

- `CONFIG_AZURE_IOT_HUB_DEVICE_ID`
- `CONFIG_AZURE_IOT_HUB_DPS_ID_SCOPE`

All instructions on how to do above can be found in the Nordic's Azure IoT Hub
library
[documentation](https://docs.nordicsemi.com/bundle/ncs-latest/page/nrf/libraries/networking/azure_iot_hub.html)

### Wi-Fi credentials

Set your Wi-Fi credentials in the `app/prj.conf` file.

## Building and running

To build the application, run one of the following commands:

```shell
cd app

# Run one of:
west build -b nrf7002dk/nrf5340/cpuapp/ns . -T app.azure_iot_hub.original
west build -b nrf7002dk/nrf5340/cpuapp/ns . -T app.azure_iot_hub.analysis
west build -b nrf7002dk/nrf5340/cpuapp/ns . -T app.azure_iot_hub.optimized_1
west build -b nrf7002dk/nrf5340/cpuapp/ns . -T app.azure_iot_hub.optimized_2
```

```shell
west flash
```

Analysis build uses shell over RTT. If you want to disable that remove
`rtt-shell` snippet for that test configuration.
