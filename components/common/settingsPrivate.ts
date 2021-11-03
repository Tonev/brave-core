export async function getPreference (key: string) {
  return await new Promise<chrome.settingsPrivate.PrefObject>(function (resolve) {
    chrome.settingsPrivate.getPref(key, pref => resolve(pref))
  })
}

export async function setPreference (key: string, value: any) {
  return await new Promise<boolean>(function (resolve) {
    chrome.settingsPrivate.setPref(key, value, null, resolve)
  })
}
