# U-Boot\_mod with support of QCA956x

This repository is a fork of https://github.com/pepe2k/u-boot_mod with extra work to support a QCA956x device.

## Releases

Binary versions at https://github.com/j-d-r/u-boot-QCA956x/releases are mostly untested because I don't have the devices.
They may not boot at all, USE THEM AT YOUR OWN RISK.

## Main differences with pepe2k version


  * Support for TP-Link EAP245 v1:
    * a QCA9563 device
    * AR8033 ethernet PHY handled by bit-banging over GPIO
    * 16MiB NOR
  * Add bootelf
  * Display more information on boot
  * Optimize binary size: builtin division, change decompression algorithm, tuning in lzma compression, etc.
  * Add completion with tab in command, variable names, and help
  * Add command line history
  * Fix in network: vlan handling, use tftpdstp and tftpsrcp to change TFTP ports
  * Enable many compiler warnings and fix them
  * Many changes in build system: out of source, parallel compilation, LTO, etc.
  * Merge of https://github.com/psyborg55/u-boot_mod


## TL;DR

Full Readme from pepe2k is [here](../README.md), here are few examples:

### Configure

```shell
u-boot> setenv ipaddr 192.168.0.1
```

or

```shell
u-boot> dhcp
```

```shell
u-boot> setenv serverip 192.168.0.2
u-boot> setenv tftpdstp 6969
u-boot> setenv ncport 8888
u-boot> setenv uboot_name u-boot.bin
u-boot> setenv bootfile openwrt-ath79-generic-tplink_eap245-v1-squashfs-sysupgrade.bin
u-boot> setenv fw_addr 0x9F040000
u-boot> saveenv
```

### TFTP

```shell
u-boot> tftpboot 0x80800000 $bootfile
u-boot> erase $fw_addr +$filesize
u-boot> cp.b $fileaddr $fw_addr $filesize
```
or
```shell
u-boot> run uboot_upg
```
or
```shell
u-boot> run fw_upg
```

### HTTP server

```shell
u-boot> httpd
```

### Netconsole

```shell
u-boot> startnc
```

connect from PC:
```shell
$ nc -u -p 6666 192.168.0.1 6666
```

go back to serial:
```shell
u-boot> startsc
```

### Overclock

```shell
u-boot> setclk
```

recover from bad settings, press reset button before plug power, safe frequencies value will be used.

### Without serial

Press reset 1 or 2 seconds after power up then leds flash once per second.

Keep button pressed for at least:
  * 3s for web based recovery
  * 5s for U-Boot console
  * 7s for network console

When HTTP server is running leds are pulsing