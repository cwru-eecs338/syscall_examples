Basic System Calls
==================

Getting the files:
------------------

If git is installed, you can just use:
<pre><code>
git clone git://github.com/cwru-eecs338/syscall_examples.git
</code></pre>

Otherwise, you can download and extract the tarball using:
<pre><code>
wget --no-check-certificate -q -O - https://github.com/cwru-eecs338/syscall_examples/tarball/master | tar -xzvf -
</code></pre>

Lessons:
--------

* Getting system time via <code>time()</code>, and displaying it in a user-friendly manner
* Getting and setting environment variables, with some issues to avoid
