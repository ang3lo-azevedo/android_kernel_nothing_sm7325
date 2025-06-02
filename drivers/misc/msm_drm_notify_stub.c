#include <linux/notifier.h>
#include <linux/export.h>

static BLOCKING_NOTIFIER_HEAD(msm_drm_notifier_list);

int msm_drm_register_client(struct notifier_block *nb)
{
    return blocking_notifier_chain_register(&msm_drm_notifier_list, nb);
}
EXPORT_SYMBOL(msm_drm_register_client);

int msm_drm_unregister_client(struct notifier_block *nb)
{
    return blocking_notifier_chain_unregister(&msm_drm_notifier_list, nb);
}
EXPORT_SYMBOL(msm_drm_unregister_client);

int msm_drm_notifier_call_chain(unsigned long val, void *v)
{
    return blocking_notifier_call_chain(&msm_drm_notifier_list, val, v);
}
EXPORT_SYMBOL(msm_drm_notifier_call_chain);

