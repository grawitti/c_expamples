#include <linux/init.h>
#include <linux/module.h>
#include <linux/pci.h>

static struct pci_device_id my_driver_id_table[] = {
	{PCI_DEVICE(0x110A, 0x2106)},
	{
		0,
	}};

MODULE_DEVICE_TABLE(pci, my_driver_id_table);

static int my_driver_probe(struct pci_dev *pdev,
						   const struct pci_device_id *ent)
{
	u16 vendor, device;

	pr_info("%s\n", __func__);

	pci_read_config_word(pdev, PCI_VENDOR_ID, &vendor);
	pci_read_config_word(pdev, PCI_DEVICE_ID, &device);

	pr_info("TEST_BSO::%s: Device vid: 0x%X pid: 0x%X\n",__func__, vendor, device);

	return 0;
}

static void my_driver_remove(struct pci_dev *pdev)
{
	pr_info("%s\n", __func__);
	struct my_driver_priv *drv_priv = pci_get_drvdata(pdev);

	if (drv_priv)
	{
		kfree(drv_priv);
	}

	pci_disable_device(pdev);
}

static struct pci_driver my_driver = {.name = "test_bso",
									  .id_table = my_driver_id_table,
									  .probe = my_driver_probe,
									  .remove = my_driver_remove};

static int __init mypci_driver_init(void)
{
	pr_info("%s\n", __func__);
	return pci_register_driver(&my_driver);
}

static void __exit mypci_driver_exit(void)
{
	pr_info("%s\n", __func__);
	pci_unregister_driver(&my_driver);
}


module_init(mypci_driver_init);
module_exit(mypci_driver_exit);
