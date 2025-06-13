# Create ZMK firmware and flash keyboard

### push to github

- make changes to keymap in local `zmk-config/config` as desired
- `git add .`
- `git commit -m "add message here"`
- `git push`

### download firmware

- open github in browser
- go to zmk cofig repo
- "actions"
- whatever is the top workflow, most recent
- "firmware" in "artifacts" section near bottom of the page
- extract zip
- Open unzipped directory with GUI file manager

### Flash Left Side

- Connect left keyboard half
- Short GRD and RST pins on nice_nano with paperclip (quick double tap)
- Drag `zmk.u2f` file to cradio (Don't worry about error message)

### Flash Right Side

- Connect right keyboard half
- Short GRD and RST pins on nice_nano with paperclip (double tap)
- Drag `zmk.u2f` file to cradio (Don't worry about error message)
