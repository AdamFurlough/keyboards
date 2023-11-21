1
- make changes to keymap in local zmk-config/config as desired
$ git add .
$ git commit
enter text describing the change in nano text editor
$ git push
will ask for this info:
    git username=AdamFurlough
    password=personal access token from bitwarden

2
open github in browser
go to zmk cofig repo
>"actions"
>whatever is the top workflow, most recent
>"firmware" in "artifacts" section near bottom of the page
extract zip

_____________________________________________
## FLASH
- Open unzipped directory with GUI file manager:

### Left
- Connect left keyboard half
- Short GRD and RST pins on nice_nano with paperclip (quick double tap)
- Drag zmk.u2f file to cradio (Don't worry about error message)

### Right
- Connect right keyboard half
- Short GRD and RST pins on nice_nano with paperclip (double tap)
- Drag zmk.u2f file to cradio (Don't worry about error message)