#include "qemu/osdep.h"
#include "qemu/log.h"
#include "qemu/units.h"
#include "hw/pci/pci.h"
#include "hw/pci/msi.h"
#include "qemu/timer.h"
#include "qom/object.h"
#include "qemu/main-loop.h" /* iothread mutex */
#include "qemu/module.h"
#include "qapi/visitor.h"

#define TYPE_NIHAO "nihao"

typedef struct NihaoState {
    PCIDevice pdev;
    unsigned int r0;
} NihaoState;

static void nihao_realize(PCIDevice *pdev, Error **errp) {
    return;
}

static void nihao_class_init (ObjectClass *class, const void *data) {
    PCIDeviceClass *k = PCI_DEVICE_CLASS(class);
    
    k->realize = nihao_realize;
    k->vendor_id = PCI_VENDOR_ID_QEMU;
    k->device_id = 0xbeef;
    k->revision = 0x10;
    k->class_id = PCI_CLASS_OTHERS;
}

static void nihao_instance_init(Object *obj) {
    return;
}

static InterfaceInfo interfaces[] = {
    { INTERFACE_CONVENTIONAL_PCI_DEVICE },
    { },
};

static const TypeInfo nihao_type = {
    .name = TYPE_NIHAO,
    .parent = TYPE_PCI_DEVICE,
    .instance_size = sizeof(NihaoState),
    .instance_init = nihao_instance_init,
    .class_init = nihao_class_init,
    .interfaces = interfaces,
};

static void nihao_register_types(void) {
    type_register_static(&nihao_type);
}

type_init(nihao_register_types)
