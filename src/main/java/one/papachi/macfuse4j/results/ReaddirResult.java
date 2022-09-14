package one.papachi.macfuse4j.results;

import java.util.Iterator;

public record ReaddirResult(int status, Iterator<DirEntry> result) {
}
