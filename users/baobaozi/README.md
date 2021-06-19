# How to get started with QMK stuff

 1. `brew install qmk/qmk/qmk`
 1. Make a fork of `https://github.com/qmk/qmk_firmware.git` — follow https://docs.github.com/en/free-pro-team@latest/github/getting-started-with-github/fork-a-repo if you don’t know what to do
 1. In CLI, clone your fork locally: `git clone https://${yourUsername}@github.com/${yourUsername}/qmk_firmware.git`
 1. If you don’t have the main QMK repo configured as a fork (check with `git remote -v`) then add it with `git remote add upstream https://github.com/qmk/qmk_firmware.git` — you can check it’s there with the same `git remote -v` command
 1. `make git-submodule`
 1. Add `export PATH="/usr/local/opt/avr-gcc@8/bin:$PATH"` and `export PATH="/usr/local/opt/arm-gcc-bin@8/bin:$PATH"` to your `.zshrc` or `.bash_profile` or whatever you use. At time of writing 2020/05/31 it’s `@8` (version 8,) but maybe by the time you come check back, it’s a more recent version. You may also be able to check and get this all automatically done with the `qmk doctor` command
 1. Do one of three things:
    - `make kbdfans/kbd67/mkiirgb/v2:baobaozi`, `make redox:baobaozi`, `make ut472:baobaozi`, or `make ymdk/ymd67:baobaozi` (don’t prepend with relative path of `keyboards/`) and then use QMK Toolbox to flash
    - if you want to do the entire thing in CLI, `qmk flash -kb kbdfans/kbd67/mkiirgb/v2 -km baobaozi` will make and then begin to flash. Get your board into reset mode to flash it by the time it starts, or it retries every 5s for a while (so I start to trigger the safe reset tap dance when it’s halfway making)
    - ooh, and if you still want to use make, but also flash, but also apply CLI flags, you can do: `make redox:baobaozi:flash CONSOLE_ENABLE=yes COMMAND_ENABLE=no`

You have to specify `:dfu` for flashing the Elite-C instead of `:flash`. If you use `EE_HANDS` (so no matter which side you plug in of your split, the right is always the right, the left is always the left) then you can use `:dfu-split-left`, `:dfu-split-right` for Elite-Cs, and `:avrdude-split-left`, `:avrdude-split-right` for Pro Micros

## When QMK gets updated

Follow the instructions for setting a remote upstream: https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/configuring-a-remote-for-a-fork

You’ll want to grab all the changes from QMK but not dirty your fork with merge commits. Make sure your branch is clean, then:

 1. `git checkout master`
 1. `git fetch upstream`
 1. `git reset --hard upstream/master`
 1. `git push`
 1. `git checkout ${mybranch}` — replace with your working branch name
 1. `git rebase master`

They also have a weird develop branch (I say weird because it doesn’t seem to be in sync with master) so I keep that exactly the same as QMK’s, too (with the above process.)

So, I called my own master branch, `mingster`, where I will `--ff-only` merge my features to. If ever I were thinking of merging my stuff into QMK’s repo, I’d make sure it’s clean enough to do so.

I also have a remote set up for sevanteri’s early combo branch, since it’s not merged yet: https://github.com/sevanteri/qmk_firmware/tree/early_combo

It allows you to have overlapping combos, combos on top of mod-taps and layer-taps, combo tapping term per combo, and variable combo length. It is super good.

## What I’ve done

I’ve put my macros, definitions, and tap dances into my users directory, so I can share them between keymaps (DRY!) I also put layout abbrs in a separate file in my user directory, so I can reuse the same rows-of-5-columns for every layout: now, adding a new keyboard takes just a couple of minutes!

I keep line comments in my keymaps that represent the keys and the (rough) positions of said keys, so you can get a visual feel, without being limited by the GUI configurator.
