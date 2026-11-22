# Calc

This is meant to be a calculator inspired by Emacs' **calc**. 
I like the concept of the declare first, do later mindset, where you note down all the values you would need for a certain problem, and then 
rearrange it in order to do things in the right order.
Emacs' calc doesn't *really* emulate this. So I'm gonna try do it myself using **termbox2** and c++.

Problem is, it currently doesn't really do anything. That's because I was initially planning to try to do this in *rust* with *ratatui*. But 
that didn't seem to be as intuitive as I'd hoped (Changed my mind more that half way through). So I'm sticking to c++. I tried things _FTXUI_ but now I've decided on the
more barebones *termbox2*. FTXUI meant I had to spend more time learning, but now, I can spend more time doing, so hopefully progress will be faster!.  
<img width="1672" height="1323" alt="image" src="https://github.com/user-attachments/assets/19f0e1ad-a16c-48a9-a91e-e73cde3406a5" />

So right now it just has a box with a stack and a little text box at the bottom. If you press any number (decimal point, or minus sign), it will appear in the text box at the bottom,
if you press enter, it gets pushed to the stack at the top. You can use *j* and *k* to move your focus in the stack and *v* to toggle highlighting mode.

Keep in mind that I termbox2 only gives you the ability to get input, move the cursor, and print stuff at specific coordinates at the screen pretty much. So to me this is impressive.

But yeah doesn't really work as a calculator yet.
## If you wanna try it for some reason
Go to the releases and follow the instructions there.


