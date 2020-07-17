# Arrays and String 

- what can be asked for array can be asked for string.
- use String Builder as it avoids unnecessary copies as strings are immutable.
```java
import java.lang.StringBuilder;

StringBuilder sb = new StringBuilder
sb.append("x");
sb.insert(sb.length(), "x");
sb.toString();
// sb.insert - at any place in string
// sb.append - at last only
// StringBuilder - unsync, not concurrent
// StringBuffer - sync, concurrent
```
- Know HashTable (java.util.HashTable), ArrayList (java.util.ArrayList)