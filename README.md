Basic System Calls
==================

Getting the files:
------------------

On the lab computer, you can use:
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
* Getting and setting environment variables:
  - Using <code>sprintf()</code> to construct variable strings
  - Using <code>sscanf()</code> to parse variable strings
  - Subtleties of <code>putenv()</code> and <code>getenv()</code>
